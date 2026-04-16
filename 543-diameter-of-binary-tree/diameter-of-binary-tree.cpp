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
    pair<int,int> solve(TreeNode* root) {
        if(!root) return {0,0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int d1 = left.first;
        int d2 = right.first;

        int d3 = left.second + right.second;

        return {max({d1,d2,d3}), max(left.second, right.second) + 1};
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
    }
};