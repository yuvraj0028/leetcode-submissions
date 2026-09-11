class Solution {
private:
    char convertLower(char &ch) {
        if((ch>='a' && ch
        
        <='z') || (ch>='0' && ch<='9')) {
            return ch;
        }

        return ch+32;
    }

public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        while(start<=end) {
            if(!isalnum(s[start])) {
                start++;
            } else if(!isalnum(s[end])) {
                end--;
            } else if(convertLower(s[start]) != convertLower(s[end])) {
                return false;
            } else {
                start++;
                end--;
            }
        }

        return true;
    }
};