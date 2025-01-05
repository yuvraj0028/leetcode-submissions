class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();        
        
        long long totalSum = accumulate(shifts.begin(), shifts.end(), 0LL);

        for(int i = 0; i < n; i++){
            long long ascii = s[i] - 97;
            ascii += totalSum;

            totalSum-=shifts[i];

            s[i] = (char)((ascii % 26) + 97);
        }

        return s;
    }
};