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
    void reverseNodeValues(vector<TreeNode*> &vec){
       int start = 0;
       int end = vec.size() - 1;

       while(start<end){
            int temp = vec[start]->val;
            vec[start]->val = vec[end]->val;
            vec[end]->val = temp;

            start++;
            end--; 
       }

       vec.clear();
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        int lvl = 0;

        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> vec;
            while(n--){
                TreeNode* node = q.front();
                vec.push_back(node);
                q.pop();

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(lvl%2 == 1){
                reverseNodeValues(vec);
            }
            lvl++;
        }

        return root;
    }
};