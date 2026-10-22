#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int parent = -1;
    int lockedBy = -1;
    bool locked = 0;
    unordered_set<int> descendends;

    mutable mutex descendendsLock;
    mutable shared_mutex nodeLock;
};

class Tree {
private:
    vector<unique_ptr<Node>> nodes;

    vector<int> getAncestors(int index) const {
        int curr = nodes[index]->parent;
        vector<int> ancestors;

        while(curr!=-1) {
            ancestors.push_back(curr);
            curr = nodes[curr]->parent;
        }

        reverse(ancestors.begin(), ancestors.end());
        return ancestors;
    }

    void updateAncestorsDescendends(int index, bool insert) {
        int curr = nodes[index]->parent;

        while(curr!=-1) {
            {
                lock_guard<mutex> descendendsLock(
                    nodes[curr]->descendendsLock
                );

                if(insert) {
                    nodes[curr]->descendends.insert(index);
                } else {
                    nodes[curr]->descendends.erase(index);
                }
            }
            curr = nodes[curr]->parent;
        }
    }

public:
    explicit Tree(int n) {
        nodes.reserve(n);
        for(int i = 0; i<n; i++) {
            nodes.push_back(make_unique<Node>());
        }
    }

    void setParent(int index, int parent) {
        this->nodes[index]->parent = parent;
    }

    bool lockNode(int index, int uid) {
        const vector<int> ancestors = getAncestors(index);
        vector<shared_lock<shared_mutex>> ancestorsSharedLocks;
        ancestorsSharedLocks.reserve(ancestors.size());

        // acquiring shared locks on ancestors
        for(const auto &anc : ancestors) {
            ancestorsSharedLocks.emplace_back(nodes[anc]->nodeLock);
        }

        // acquiring exclusive lock on current node
        unique_lock<shared_mutex> targetLock(
            nodes[index]->nodeLock
        );

        // if node index is already locked return false
        if(nodes[index]->locked) return false;

        // check if all the descendends are lock free, which means the set is empty
        {
            lock_guard<mutex> descendendsLock(
                nodes[index]->descendendsLock
            );
            
            if(!nodes[index]->descendends.empty()) return false;

        }

        // lock the current node
        nodes[index]->locked = 1;
        nodes[index]->lockedBy = uid;

        // update the ancestors descendends
        updateAncestorsDescendends(index, true);

        return true;
    }

    bool unlockNode(int index, int uid) {
        const vector<int> ancestors = getAncestors(index);
        vector<shared_lock<shared_mutex>> ancestorsSharedLocks;
        ancestorsSharedLocks.reserve(ancestors.size());

        // acquiring shared locks on ancestors
        for(const auto &anc : ancestors) {
            ancestorsSharedLocks.emplace_back(nodes[anc]->nodeLock);
        }

        // acquiring exclusive lock on current node
        unique_lock<shared_mutex> targetLock(
            nodes[index]->nodeLock
        );

        // validation for unlocking
        if(!nodes[index]->locked) return false;
        if(nodes[index]->lockedBy != uid) return false;

        // unlock the targetNode
        nodes[index]->locked = 0;
        nodes[index]->lockedBy = -1;

        // update the ancestors descendends
        updateAncestorsDescendends(index, false);

        return true;

    }

    bool upgradeNode(int index, int uid) {
        const vector<int> ancestors = getAncestors(index);
        vector<shared_lock<shared_mutex>> ancestorsSharedLocks;
        ancestorsSharedLocks.reserve(ancestors.size());

        // acquiring shared locks on ancestors
        for(const auto &anc : ancestors) {
            ancestorsSharedLocks.emplace_back(nodes[anc]->nodeLock);
        }

        // acquiring exclusive lock on current node
        unique_lock<shared_mutex> targetLock(
            nodes[index]->nodeLock
        );

        // validation before upgrading lock
        vector<int> descendants;
        if(nodes[index]->locked) return false;
        {
            lock_guard<mutex> descMutex(nodes[index]->descendendsLock);
            if(nodes[index]->descendends.empty()) return false;
            descendants.assign(nodes[index]->descendends.begin(), nodes[index]->descendends.end());
        }

        // exclusive lock on desc for ownership check
        sort(descendants.begin(), descendants.end());
        vector<unique_lock<shared_mutex>> descendantLocks;
        for(const auto &i : descendants) {
            descendantLocks.emplace_back(nodes[i]->nodeLock);
        }
        for(const auto &i : descendants) {
            if(nodes[i]->lockedBy != uid) return false;
        }

        // unlock all descendends and unlock their descendends
        for(const auto &i : descendants) {
            nodes[i]->lockedBy = -1;
            nodes[i]->locked = 0;
            updateAncestorsDescendends(i, false);
        }

        // now lock the current node
        nodes[index]->locked = 1;
        nodes[index]->lockedBy = uid;

        // update descendends of current node ancestors
        updateAncestorsDescendends(index, true);
        return true;
    }
};

void handleActions() {
    // n -> no of nodes, m->each nodes how many children, q -> no of queries
    int n, m, q;
    cin >> n >> m >> q;

    Tree tree(n);
    unordered_map<string, int> nodeToIndex;

    vector<string> nameToIndex(n);
    for(int i = 0; i<n; i++) {
        cin >> nameToIndex[i];
        nodeToIndex[nameToIndex[i]] = i;
    }

    queue<int> qu;
    qu.push(0);

    int idx = 1;
    while(!qu.empty()) {
        int front = qu.front();
        qu.pop();
        
        for(int i = 0; i<m && idx<n; i++, idx++) {
            tree.setParent(idx, front);
            qu.push(idx);
        }
    }
    
    vector<string> ans(q);

    unsigned int workerCount = thread::hardware_concurrency();
    if(workerCount == 0) workerCount = 4;

    // Store queries before launching workers.
    struct Query {
        int op;
        int uid;
        string name;
    };

    vector<Query> queries(q);

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].op >> queries[i].name >> queries[i].uid;
    }

    workerCount = min(workerCount, static_cast<unsigned int>(q));
    atomic<int> nextQuery{0};

    auto worker = [&]() {
        while(true) {
            int i = nextQuery.fetch_add(1);

            if(i>=q) break;

            int op = queries[i].op, uid = queries[i].uid;
            string name = queries[i].name;

            bool success = false;
            auto it = nodeToIndex.find(name);
            if(it != nodeToIndex.end()) {
                int index = it->second;
                switch (op)
                {
                case 1:
                    success = tree.lockNode(index, uid);
                    break;
                case 2:
                    success = tree.unlockNode(index, uid);
                    break;
                case 3:
                    success = tree.upgradeNode(index, uid);
                    break;
                default:
                    break;
                }
            }
            ans[i] = success ? "true" : "false";
        }
    };

    vector<thread> workerThread;
    workerThread.reserve(workerCount);

    for(unsigned int i = 0; i<workerCount; i++) {
        workerThread.emplace_back(worker);
    }

    for (thread& t : workerThread) {
        t.join();
    }

    for(const auto &i: ans) {
        cout<< i << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    handleActions();
    return 0;
}