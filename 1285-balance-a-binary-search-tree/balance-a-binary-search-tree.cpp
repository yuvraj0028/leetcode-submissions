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
    void inorder(TreeNode* root, vector<int> &vec){
        if(!root) return;

        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }

    TreeNode* buildBST(vector<int> &vec, int s, int e){
        if(s>e){
            return NULL;
        }
        
        int mid = s + (e-s)/2;

        TreeNode* root = new TreeNode(vec[mid]);
        
        root->left = buildBST(vec, s, mid-1);
        root->right = buildBST(vec, mid+1, e);

        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);

        return buildBST(vec, 0, vec.size()-1);
    }
};