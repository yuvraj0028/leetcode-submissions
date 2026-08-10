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
private:
    unordered_map<Node*, int> nodeToIndex;
    unordered_map<int, Node*> indexToNode;

    void mapRandomPointer(Node* &curr, Node* &currRes) {
        if(curr->random) {
            int randomNodeIndex = nodeToIndex[curr->random];

            if(indexToNode.find(randomNodeIndex) != indexToNode.end()) {
                currRes->random = indexToNode[randomNodeIndex];
            } else {
                Node* newRandomNode = new Node(curr->random->val);
                indexToNode[randomNodeIndex] = newRandomNode;
                currRes->random = newRandomNode;
            } 
        }
    }

    Node* deepCopySingleMap(Node* head) {
        unordered_map<Node*, Node*> oldToNew;
        Node* curr = head;

        while(curr) {
            oldToNew[curr] = new Node(curr->val);
            curr=curr->next;
        }

        curr = head;
        while(curr) {
            oldToNew[curr]->next = oldToNew[curr->next];
            oldToNew[curr]->random = oldToNew[curr->random];

            curr = curr->next;
        }

        return oldToNew[head];
    }

public:
    Node* copyRandomList(Node* head) {
        // if(!head) return nullptr;

        // int index = 0;
        // Node* curr = head;

        // while(curr) {
        //     nodeToIndex[curr] = index;
        //     index++;
        //     curr = curr->next;
        // }

        // Node* res = new Node(0);
        // Node* currRes = res;
        
        // index = 0;
        // curr = head;

        // while(curr) {
        //     if(indexToNode.find(index) != indexToNode.end()) {
        //         currRes->next = indexToNode[index];
        //         currRes = currRes->next;

        //         mapRandomPointer(curr, currRes);
        //     } else {
        //         Node* newNode = new Node(curr->val);
        //         currRes->next = newNode;
        //         currRes = currRes->next;
        //         indexToNode[index] = newNode;

        //         mapRandomPointer(curr, currRes);
        //     }
        //     index++;
        //     curr = curr->next;
        // }

        // return res->next;


        return deepCopySingleMap(head);

    }
};