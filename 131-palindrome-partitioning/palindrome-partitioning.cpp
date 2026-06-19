class Solution {
private:
    vector<vector<string>> ans;

    bool isPalindrome(string &s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void solve(string &str, int index, vector<string> &palindromes) {
        if(index == str.size()) {
            ans.push_back(palindromes);
            return;
        }

        for(int end = index; end < str.size(); end++) {
            if(isPalindrome(str, index, end)) {
                palindromes.push_back(str.substr(index, end - index + 1));
                solve(str, end + 1, palindromes);
                palindromes.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> palindromes;
        solve(s, 0, palindromes);
        return ans;
    }
};