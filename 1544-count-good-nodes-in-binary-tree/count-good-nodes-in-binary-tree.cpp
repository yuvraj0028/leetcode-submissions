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
    void solve(TreeNode* root, int maxi, int &cnt) {
        if(!root) return;

        if(root->val >= maxi && maxi != INT_MIN) cnt++;

        maxi = max(maxi, root->val);
        solve(root->left, maxi, cnt);
        solve(root->right, maxi, cnt);
    }
public:


    int goodNodes(TreeNode* root) {
        if(!root) return 0;

        int maxi = INT_MIN;
        int cnt = 1;

        solve(root, maxi, cnt);
        return cnt;
    }
};