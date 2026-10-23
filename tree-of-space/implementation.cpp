#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int parent = -1;
    int lockedBy = -1;
    bool isLocked = 0;
    unordered_set<int> lockedDescendends;
};

vector<Node> treeNodes;
unordered_map<string, int> nodeToIndex;

bool lock(int index, int id) {
    // validate current node
    if(treeNodes[index].isLocked) return false;
    if(!treeNodes[index].lockedDescendends.empty()) return false;

    // validate parent is not locked
    int curr = treeNodes[index].parent;
    while(curr!=-1) {
        if(treeNodes[curr].isLocked) return false;
        curr = treeNodes[curr].parent;
    }

    // validation passed now locking current node
    treeNodes[index].isLocked = 1;
    treeNodes[index].lockedBy = id;

    // current node locked now filling up ancestors descendends
    curr = treeNodes[index].parent;
    while(curr!=-1) {
        treeNodes[curr].lockedDescendends.insert(index);
        curr = treeNodes[curr].parent;
    }

    return true;
}

bool unlock(int index, int id) {
    // validate node is locked and locked by same user id
    if(!treeNodes[index].isLocked || treeNodes[index].lockedBy != id) return false;

    // unlock current node
    treeNodes[index].isLocked = 0;
    treeNodes[index].lockedBy = -1;

    // remove the des from anc
    int curr = treeNodes[index].parent;
    while(curr!=-1) {
        treeNodes[curr].lockedDescendends.erase(index);
        curr = treeNodes[curr].parent;
    }

    return true;
}

bool upgradeLock(int index, int id) {
    // validate node -> current one should not be locked and should have atleast one desc
    if(treeNodes[index].isLocked) return false;
    if(treeNodes[index].lockedDescendends.empty()) return false;

    // check if desc has different ownership
    unordered_set<int> &descs = treeNodes[index].lockedDescendends;
    for(const int &desc: descs) {
        if(treeNodes[desc].lockedBy != id) return false;
    }

    // check anc is not locked
    int curr = treeNodes[index].parent;
    while(curr!=-1) {
        if(treeNodes[curr].isLocked) return false;
        curr = treeNodes[curr].parent;
    }

    // unlock desc
    unordered_set<int> descCopy(descs.begin(), descs.end());
    for(const int desc: descCopy) {
        unlock(desc, id);
    }

    // lock curr node
    return lock(index, id);
}

int getDepth(int index) {
    int depth = 0;

    while (index != -1) {
        depth++;
        index = treeNodes[index].parent;
    }

    return depth;
}

int LCA(int u, int v) {
    int depthU = getDepth(u);
    int depthV = getDepth(v);

    // Bring both nodes to the same depth.
    while (depthU > depthV) {
        u = treeNodes[u].parent;
        depthU--;
    }

    while (depthV > depthU) {
        v = treeNodes[v].parent;
        depthV--;
    }

    // Move both upward until they meet.
    while (u != v) {
        u = treeNodes[u].parent;
        v = treeNodes[v].parent;
    }

    return u;
}

void handleActions() {
    // n -> no of nodes, m->each nodes how many children, q -> no of queries
    int n, m, q;
    cin >> n >> m >> q;

    treeNodes.assign(n,Node());
    nodeToIndex.clear();

    vector<string> nameToIndex(n);
    for(int i = 0; i<n; i++) {
        cin >> nameToIndex[i];
    }

    nodeToIndex[nameToIndex[0]] = 0;
    
    queue<int> qu;
    qu.push(0);

    int idx = 1;
    while(!qu.empty()) {
        int front = qu.front();
        qu.pop();
        
        for(int i = 0; i<m && idx<n; i++, idx++) {
            treeNodes[idx].parent = front;
            nodeToIndex[nameToIndex[idx]] = idx;
            qu.push(idx);
        }
    }
    
    vector<string> ans;
    ans.reserve(q);
    for(int i = 0; i<q; i++) {
        int op, uid;
        string name;
        cin >> op >> name >> uid;

        bool success = false;
        auto it = nodeToIndex.find(name);
        if(it != nodeToIndex.end()) {
            int index = it->second;
            if(op==1) success = lock(index, uid);
            if(op==2) success = unlock(index, uid);
            if(op==3) success = upgradeLock(index, uid);
        }
        ans.push_back(success ? "true" : "false");
    }

    for(const auto &i: ans) {
        cout<< i <<endl;
    }

}

int main() {
    handleActions();
    return 0;
}