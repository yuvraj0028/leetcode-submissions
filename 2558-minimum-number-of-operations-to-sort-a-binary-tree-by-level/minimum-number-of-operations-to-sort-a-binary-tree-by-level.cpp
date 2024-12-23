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
    void countSwaps(vector<int> &level, int &swaps){
        int n = level.size();
        // selection sort
        for(int i = 0;i<n;i++){
            int minIndex = i;
            for(int j = i; j<n;j++){
                if(level[j]<level[minIndex]){
                    minIndex = j;
                }
            }
            // if some bigger value is before index then we need to swap
            if(i!=minIndex){
                swaps++;
                swap(level[i], level[minIndex]);
            }
        }
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int swaps = 0;
        
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i = 0; i<n;i++){
                TreeNode* front = q.front();
                level.push_back(front->val);
                q.pop();
            
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            // counting swaps
            countSwaps(level, swaps);
        }

        return swaps;
    }
};