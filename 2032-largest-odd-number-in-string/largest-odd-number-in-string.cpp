class Solution {
private:

public:
    string largestOddNumber(string num) {
        int n = num.size();

        int index = -1;

        for(int i = n-1; i>=0 ;i--){
            int number = num[i] - '0';

            if(number % 2 != 0){
                index = i;
                break;
            }
        }

        return index == -1 ? "" : num.substr(0,index+1);
    }
};