class Solution {
private:
    vector<string> combn;
    void solve(string &digits, string output, int i, string map[]) {
        if(i>=digits.size()) {
            combn.push_back(output);
            return;
        }

        int index = digits[i] - '0';
        string value = map[index];

        for(int in = 0; in<value.size(); in++) {
            output.push_back(value[in]);
            solve(digits, output, i+1, map);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return combn;

        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, "", 0, mapping);

        return combn;
    }
};