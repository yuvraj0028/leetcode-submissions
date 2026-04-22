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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int > > ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            while(n--) {
                auto node = q.front();
                q.pop();

                if(node == NULL) {
                    ans.push_back(temp);
                    temp.clear();
                    continue;
                } else {
                    temp.push_back(node->val);
                }

                if(node->left) {
                    q.push(node->left);
                }

                if(node->right) {
                    q.push(node->right);
                }
            }

            if(!q.empty()) q.push(NULL);
        }

        return ans;
    }
};