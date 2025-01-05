class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();

        vector<int> shift(n+1);

        for(const vector<int> &sh : shifts){
            int start = sh[0];
            int end = sh[1];
            int dir = sh[2];

            int shiftValue = (dir == 1) ? 1 : -1;

            shift[start] += shiftValue;

            if(end + 1 < n){
                shift[end+1] -= shiftValue;
            }
        }

        for(int i = 1; i<n; i++){
            shift[i] += shift[i-1];
        }

        for(int i = 0; i<n; i++){
            int newChar = (s[i] - 'a' + shift[i]) % 26;
            
            if(newChar < 0) newChar += 26;

            s[i] = newChar + 'a';
        }

        return s;
    }
};