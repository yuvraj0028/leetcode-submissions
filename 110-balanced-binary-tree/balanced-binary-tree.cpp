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
    pair<bool,int> solve(TreeNode* root) {
        if(!root) return {1,0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        bool leftCheck = left.first;
        bool rightCheck = right.first;

        int heightLeft = left.second;
        int heightRight = right.second;

        bool isValid = abs(heightLeft - heightRight) <= 1;

        auto check = leftCheck && rightCheck && isValid;
        auto height = max(heightLeft, heightRight) + 1;

        return {check, height}; 
    }

public:
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};