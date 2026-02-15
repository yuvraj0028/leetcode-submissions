class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;

        int i = a.size() -1 , j = b.size()-1;

        string ans = "";

        while(i>=0 && j>=0){
            int x = a[i] - '0';
            int y = b[j] - '0';

            if(x+y+carry == 2){
                ans.push_back('0');
                carry = 1;
            } else if(x+y+carry == 3){
                ans.push_back('1');
                carry = 1;
            } else {
                int sum = x+y+carry;
                ans.push_back(char(sum + '0'));
                carry = 0;
            }

            i--;j--;
        }

        while(i>=0){
            int x = a[i] - '0';

            if(x+carry >1){
                ans.push_back('0');
                carry =1;
            } else {
                int sum = x+carry;
                ans.push_back(char(sum + '0'));
                carry = 0;
            }

            i--;
        }

        while(j>=0){
            int x = b[j] - '0';

            if(x+carry >1){
                ans.push_back('0');
                carry =1;
            } else {
                int sum = x+carry;
                ans.push_back(char(sum + '0'));
                carry = 0;
            }

            j--;
        }

        if(carry == 1){
            ans.push_back('1');
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};