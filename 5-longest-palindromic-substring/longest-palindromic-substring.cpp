class Solution {
private:
    bool checkPalindrome(string &s, int i, int j) {
        if(i>=j) return true;

        if(s[i] == s[j]) {
            return checkPalindrome(s, i+1, j-1);
        }

        return false;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;
        string result = "";

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                int currLen = j-i+1;
                if(checkPalindrome(s, i, j)) {
                    if(currLen > maxLen) {
                        maxLen = currLen;
                        result = s.substr(i, j-i+1);
                    }
                }
            }
        }

        return result;
    }
};