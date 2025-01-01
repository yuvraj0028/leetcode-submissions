class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int maxi = INT_MIN;

        int oneSum = count(s.begin(), s.end(), '1');
        int zeroSum = 0;

        for(int i = 0; i<n-1;i++){
            if(s[i] == '1') oneSum--;
            else zeroSum++;

            maxi = max(maxi, oneSum + zeroSum);
        }

        return maxi;
    }
};