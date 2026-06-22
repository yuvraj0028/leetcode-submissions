class Solution {
private:
    vector<vector<string>> ans;
    bool isPalindrome(string str, int i, int j) {

        while(i<=j){
            if(str[i++] != str[j--]) {
                return false;
            }
        }

        return true;
    }

    void solve(vector<string> &vec, string &str, int i) {
        if(i==str.size()) {
            ans.push_back(vec);
            return;
        }

        for(int j = i; j<str.size(); j++) {
            if(isPalindrome(str, i, j)) {
                vec.push_back(str.substr(i, j-i+1));
                solve(vec, str, j+1);
                vec.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        solve(vec, s, 0);

        return ans;
    }
};