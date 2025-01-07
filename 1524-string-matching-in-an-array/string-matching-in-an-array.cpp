class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();

        set<string> st;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(words[i].find(words[j]) != string::npos && i!=j){
                    st.insert(words[j]);
                }
            }
        }

        vector<string> ans(st.begin(), st.end());

        return ans;

    }
};