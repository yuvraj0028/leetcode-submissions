class Solution {
private:
    bool solve(string &s){
        if(s.size() == 2){
            if(s[0] == s[1]) return 1;
            return 0;
        }

        string newString = "";

        for(int i = 0; i<s.size()-1; i++){
            newString += char((int(s[i] - '0') + int(s[i+1] - '0'))%10) + '0';
        }

        return solve(newString);
    }
public:
    bool hasSameDigits(string s) {
        return solve(s);
    }
};