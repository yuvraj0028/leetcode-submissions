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
private:
    int findHeight(TreeNode* root){
        if(!root) return 0;

        int left = findHeight(root->left);
        int right = findHeight(root->right);
    
        return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool isValid = abs(findHeight(root->left) - findHeight(root->right)) <= 1;

        return left && right && isValid;
    }
};