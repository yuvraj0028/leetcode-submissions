class Solution {
private:
    vector<vector<bool > > visited;
    bool solve(vector<vector<char>>& board, string word, int i, int j, int index) {
        if(index == word.size()) return true;

        if(
            i<0 || j<0 ||
            i >= board.size() ||
            j >= board[0].size() ||
            visited[i][j] ||
            board[i][j] != word[index]
        ) return false;

        visited[i][j] = 1;

        int delRow[4] = {1, 0, -1, 0};
        int delCol[4] = {0, 1, 0, -1};

        for(int idx = 0; idx < 4; idx++) {
            if(solve(board, word, delRow[idx] + i, delCol[idx] + j, index+1)){
                return true;
            }
        }
        visited[i][j] = 0;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0; i<board.size(); i++) {
            for(int j = 0; j<board[0].size(); j++) {
                visited.assign(board.size(), vector<bool>(board[0].size(), 0));
                if(solve(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};