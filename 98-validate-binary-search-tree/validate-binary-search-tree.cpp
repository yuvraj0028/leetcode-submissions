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
public:
    void inorder(TreeNode* root, vector<int> &vec) {
        if(!root) return;

        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);

    }

    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);

        for(int i = 1; i<vec.size(); i++) {
            if(vec[i-1] >= vec[i]) return false;
        }

        return true;
    }
};