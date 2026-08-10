/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        int index = 0;
        Node* curr = head;

        unordered_map<Node*, int> nodeToIndex;
        unordered_map<int, Node*> indexToNode;

        while(curr) {
            nodeToIndex[curr] = index;
            index++;
            curr = curr->next;
        }

        Node* res = new Node(0);
        Node* currRes = res;
        
        index = 0;
        curr = head;

        while(curr) {
            if(indexToNode.find(index) != indexToNode.end()) {
                currRes->next = indexToNode[index];
                currRes = currRes->next;

                if(curr->random) {
                    int randomNodeIndex = nodeToIndex[curr->random];
                    cout<<curr->val<<" - "<<curr->random->val<<" - "<<randomNodeIndex<<endl;

                    if(indexToNode.find(randomNodeIndex) != indexToNode.end()) {
                        currRes->random = indexToNode[randomNodeIndex];
                    } else {
                        Node* newRandomNode = new Node(curr->random->val);
                        indexToNode[randomNodeIndex] = newRandomNode;
                        currRes->random = newRandomNode;
                    } 
                }
            } else {
                Node* newNode = new Node(curr->val);
                currRes->next = newNode;
                currRes = currRes->next;
                indexToNode[index] = newNode;

                if(curr->random) {
                    int randomNodeIndex = nodeToIndex[curr->random];
                    cout<<curr->val<<" - "<<curr->random->val<<" - "<<randomNodeIndex<<endl;

                    if(indexToNode.find(randomNodeIndex) != indexToNode.end()) {
                        currRes->random = indexToNode[randomNodeIndex];
                    } else {
                        Node* newRandomNode = new Node(curr->random->val);
                        indexToNode[randomNodeIndex] = newRandomNode;
                        currRes->random = newRandomNode;
                    }
                }
            }
            index++;
            curr = curr->next;
        }

        return res->next;

    }
};