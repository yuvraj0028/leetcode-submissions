class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n-1;

        while(i < m && j>=0){
            int elem = matrix[i][j];

            if(elem == target){
                return true;
            }

            if(elem > target){
                j--;
            } else {
                i++;
            }
        }
        
        return false;
    }
};