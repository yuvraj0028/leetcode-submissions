class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();

        if (numRows == 1 || n <= numRows) return s;

        vector<vector<char > > vec(numRows, vector<char>(n, '\0'));
        string ans = "";
        int row = 0, col = 0;

        for(int i = 0; i<n;){
            while(row<numRows && i<n){
                vec[row][col] = s[i];
                row++; i++;
            }

            row -= 2;
            col++;

            while(row>0 && i<n){
                vec[row][col] = s[i];
                row--; col++;
                i++;
            }
        }

        for(const auto &i : vec){
            for(const auto &j : i){
                if(j != '\0'){
                    ans+=j;
                }
            }
        }

        return ans;
    }
};