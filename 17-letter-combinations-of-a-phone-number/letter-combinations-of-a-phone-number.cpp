class Solution {
private:
    vector<string> combinations;
    void solve(string &digits, int i, string* map, string &str) {
        if(i == digits.size()) {
            combinations.push_back(str);
            return;
        }

        int index = digits[i] - '0';
        string pattern = map[index];

        for(int idx = 0; idx < pattern.size(); idx++) {
            str.push_back(pattern[idx]);
            solve(digits, i+1, map, str);
            str.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        string map[10] = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        string str = "";
        solve(digits, 0, map, str);
        return combinations;
    }
};