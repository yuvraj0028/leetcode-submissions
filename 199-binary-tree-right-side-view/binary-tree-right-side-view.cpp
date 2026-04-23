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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()) {
            int n = q.size();

            while(n--) {
                auto front = q.front();
                q.pop();

                if(!q.empty() && q.front() == NULL) {
                    ans.push_back(front->val);
                }
                
                if(front == NULL) continue;

                if(front->left) q.push(front->left);

                if(front->right) q.push(front->right);
            }

            if(!q.empty()) q.push(NULL);
        }

        return ans;
    }
};