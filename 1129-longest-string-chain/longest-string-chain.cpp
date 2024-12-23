class Solution {
private:
    bool compareString(string &s1, string &s2){
        if(s1.size() != s2.size()+1) return false;

        int first = 0, second = 0;

        while(first<s1.size()){
            if(s1[first] == s2[second]){
                first++;
                second++;
            } else {
                first++;
            }
        }

        return first == s1.size() && second == s2.size();
    }

public:
    int longestStrChain(vector<string>& words) {
        int maxi = 1;
        int n = words.size();

        sort(words.begin(), words.end(),[&](const string &s1, const string &s2){
            return s1.size() < s2.size();
        });

        vector<int> dp(n,1);

        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(compareString(words[i],words[j]) && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }

            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }

        return maxi;
    }
};