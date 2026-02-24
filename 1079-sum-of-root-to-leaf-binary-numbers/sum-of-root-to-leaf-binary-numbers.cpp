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
    string str = "";
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;

        str+=to_string(root->val);

        if(!root->left && !root->right){
            string temp = str;
            if(str.size()>=1) str.pop_back();

            return temp.empty() ? 0 : stoi(temp, nullptr, 2);
        }

        int left = sumRootToLeaf(root->left);
        int right = sumRootToLeaf(root->right);

        if(str.size()>=1) str.pop_back();
        return left + right;
    }
};