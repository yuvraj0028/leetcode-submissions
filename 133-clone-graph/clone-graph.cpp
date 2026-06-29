/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void dfs(Node* node, unordered_map<int, bool> &visited, unordered_map<int, Node*> &ref, Node* &newNode) {
        if(!node) return;

        int val = node->val;
        vector<Node*> neighbors = node->neighbors;
        visited[val] = 1;

        if(ref.find(val) == ref.end()) {
            newNode = new Node(val);
            ref[val] = newNode;
        }

        for(const auto next: neighbors) {
            Node* nextNode = NULL;
            if(ref.find(next->val) == ref.end()) {
                nextNode = new Node(next->val);
                ref[next->val] = nextNode;
            } else {
                nextNode = ref[next->val];
            }
            newNode->neighbors.push_back(nextNode);
            if(!visited[next->val]){
                dfs(next, visited, ref, nextNode);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        Node* newNode = NULL;
        unordered_map<int, bool> visited;
        unordered_map<int, Node*> ref;
        dfs(node, visited, ref, newNode);
        return newNode;
    }
};