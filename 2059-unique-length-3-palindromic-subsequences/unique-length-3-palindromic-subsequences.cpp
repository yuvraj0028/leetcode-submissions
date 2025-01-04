class Solution {
public:
    int countPalindromicSubsequence(string s) {
       int n = s.size(), ans = 0;

       vector<int> maxi(26, INT_MIN);
       vector<int> mini(26, INT_MAX);

       for(int i = 0;i<n; i++){
            int index = s[i] - 'a';
            maxi[index] = max(maxi[index], i);
            mini[index] = min(mini[index], i);
       }

       for(int i = 0; i<26; i++){
            if(maxi[i] == INT_MIN || mini[i] == INT_MAX){
                continue;
            }

            unordered_set<char> st;

            for(int j = mini[i] + 1; j < maxi[i]; j++){
                st.insert(s[j]);
            }

            ans+=st.size();
       }

       return ans;
    }
};