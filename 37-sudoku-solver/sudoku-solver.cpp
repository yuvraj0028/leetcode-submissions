class Solution {
private:
    bool isSafe(int row, int col, int val, vector<vector<char>>& board){
        int N = 9;
        for(int i = 0;i<N; i++){
            if(board[row][i] == val) return false;
            if(board[i][col] == val) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        int N = 9;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(board[i][j] == '.'){
                    for(int k = '1';k<='9';k++){
                        if(isSafe(i,j,k,board)){
                            board[i][j] = k;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }

                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};