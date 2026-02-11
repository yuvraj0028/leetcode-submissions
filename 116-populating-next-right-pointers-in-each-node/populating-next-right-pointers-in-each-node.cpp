/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void solve(Node* root){
        if(!root || !root->left) return;

        root->left->next = root->right;

        if(root->next){
            root->right->next = root->next->left;
        }

        solve(root->left);
        solve(root->right);
    }

    // void printTree(Node* root){
    //     if(!root) return;

    //     if(root->next){
    //         cout<<root->next->val<<endl;
    //     } else {
    //         cout<<"NULL"<<endl;
    //     }

    //     printTree(root->left);
    //     printTree(root->right);
    // }

public:
    Node* connect(Node* root) {
        solve(root);
        // printTree(root);
        return root;
    }
};