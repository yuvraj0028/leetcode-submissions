class Solution {
private:
    bool checkValidBlock(int i, int j) {
        if(
            (i == 0 && j == 0) ||
            (i == 0 && j == 3) || 
            (i == 0 && j == 6) ||
            (i == 3 && j == 0) ||
            (i == 3 && j == 3) || 
            (i == 3 && j == 6) ||
            (i == 6 && j == 0) ||
            (i == 6 && j == 3) || 
            (i == 6 && j == 6)
        ) {
            return true;
        }

        return false;
    }

    bool checkBlock(int i, int j, vector<vector<char>>& board) {
        vector<int> freq(10, 0);

        for(int row = i; row<(i+3); row++) {
            for(int col = j; col<j+3; col++) {
                char ch = board[row][col];
                if(ch != '.') {
                    int num = ch - '0';
                    freq[num]++;
                }
            }
        }

        for(const int &num : freq) {
            if(num>1) return false;
        }

        return true;
    }

    bool checkRow(int col, vector<vector<char>>& board) {
        vector<int> freq(10, 0);
        int n = board.size();

        for(int row = 0; row<n; row++) {
            char ch = board[row][col];
            if(ch != '.') {
                int num = ch - '0';
                freq[num]++;
            }
        }

        for(const int &num : freq) {
            if(num>1) return false;
        }

        return true;
    }

    bool checkCol(int row, vector<vector<char>>& board) {
        vector<int> freq(10, 0);
        int n = board.size();

        for(int col = 0; col<n; col++) {
            char ch = board[row][col];
            if(ch != '.') {
                int num = ch - '0';
                freq[num]++;
            }
        }

        for(const int &num : freq) {
            if(num>1) return false;
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        
        for(int i = 0; i<n; i++) {
            for(int j = 0;j<n; j++) {
                if(checkValidBlock(i,j)) {
                    if(!checkBlock(i,j,board)) {
                        return false;
                    }
                }

                if(!checkRow(j, board)) {
                    return false;
                }

                if(!checkCol(i, board)) {
                    return false;
                }
            }
        }

        return true;
    }
};