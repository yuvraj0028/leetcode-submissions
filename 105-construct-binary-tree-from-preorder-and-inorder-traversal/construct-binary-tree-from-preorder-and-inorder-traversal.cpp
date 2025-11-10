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
    TreeNode* solve(
        vector<int>& inorder, 
        int inorderStart,
        int inorderEnd,
        vector<int>& preorder,
        int preorderStart,
        int preorderEnd,
        unordered_map<int,int> &mp
    )
    {
        if(inorderStart>inorderEnd || preorderStart > preorderEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preorderStart]);
        int inorderRootIndex = mp[preorder[preorderStart]];
        int pos = inorderRootIndex - inorderStart;

        root->left = solve(
            inorder,
            inorderStart,
            inorderRootIndex-1,
            preorder,
            preorderStart+1,
            preorderStart+pos,
            mp
        );

        root->right = solve(
            inorder,
            inorderRootIndex+1,
            inorderEnd,
            preorder,
            preorderStart+pos+1,
            preorderEnd,
            mp
        );

        return root;
    }


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i = 0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }

        return solve(
            inorder,
            0,
            inorder.size()-1,
            preorder,
            0,
            preorder.size()-1,
            mp
        );
    }
};