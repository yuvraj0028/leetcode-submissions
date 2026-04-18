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
        bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;

        if(!p && q) return false;

        if(p && !q) return false;

        if(p->val != q->val) return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        return left && right;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        bool check = isSameTree(root, subRoot);
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
    
        return left || right || check;
    }
};