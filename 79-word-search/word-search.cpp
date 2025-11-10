class Solution {
private:
    bool solve(vector<vector<char>>& board, string word, int i, int j, int k){
        if(k>=word.size()) return 1;

        if(i<0 || i>= board.size() || j<0 || j>=board[0].size() || board[i][j] != word[k] || board[i][j] == '.'){
            return false;
        }

        if(word.size() == 1 && board[i][j] == word[k]) return 1;

        int delX[] = {1,0,-1,0};
        int delY[] = {0,-1,0,1};

        char ch = board[i][j];
        board[i][j] = '.';
        bool temp = 0;

        for(int dir= 0; dir<4; dir++){
            temp = temp || solve(board, word, i + delX[dir],j + delY[dir], k+1);
        }
        board[i][j] = ch;
        return temp;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<board[i].size(); j++){
                if(solve(board,word,i,j,0)){
                    return 1;
                }
            }
        }
        return 0;
    }
};