/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void inorder(TreeNode* root, vector<int> &v){
        if(!root) return;

        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }

    void solve(TreeNode* root, vector<int> &v, int &i){
        if(!root) return;
        
        solve(root->left, v, i);
        root->val = v[i++];
        solve(root->right, v, i);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> v;
        int i = 0;

        inorder(root,v);

        for(int i = v.size() - 2;i>=0;i--){
            v[i] = v[i] + v[i+1];
        }

        solve(root,v,i);

        return root;
    }
};