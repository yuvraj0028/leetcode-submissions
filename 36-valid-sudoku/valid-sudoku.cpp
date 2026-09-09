class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        bool rows[10][10] = {false};
        bool cols[10][10] = {false};
        bool blocks[10][10] = {false};
    
        for(int row = 0; row<n; row++) {
            for(int col = 0; col<n; col++) {
                char ch = board[row][col];

                if(ch == '.') continue;

                int num = ch - '0';
                int block = (row/3) * 3 + (col/3);

                if(rows[row][num] || cols[col][num] || blocks[block][num]) {
                    return false;
                }

                rows[row][num] = 1;
                cols[col][num] = 1;
                blocks[block][num] = 1;
            }
        }

        return true;
    }
};