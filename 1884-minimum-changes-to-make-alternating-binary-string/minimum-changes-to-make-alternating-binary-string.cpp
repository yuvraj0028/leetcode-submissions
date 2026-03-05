class Solution {
public:
    int minOperations(string s) {
        string str1 = "0", str2 = "1";
        int cnt1 = 0, cnt2 = 0;
        int n = s.size();

        if(n==1) return 0;

        for(int i = 1; i<n; i++){
            if(i%2 == 0) {
                str1+='0';
                str2+='1';
            } else {
                str1+='1';
                str2+='0';
            }
        }

        for(int i = 0; i < n; i++){
            if(s[i]!=str1[i]) cnt1++;
            if(s[i]!=str2[i]) cnt2++;
        }

        return min(cnt1, cnt2);
    }
};