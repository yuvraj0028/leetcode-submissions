class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            vector<int> freq(26);
            unordered_set<char> st;

            for(int j = i; j<s.size(); j++){
                freq[s[j] - 'a']++;
                st.insert(s[j]);
                
                char startChar = *st.begin();
                int startCharFreq = freq[startChar-'a'];
                int tempAns = ans;
                bool changed = true;
                for(const char &ch : st){
                    if(startCharFreq == freq[ch-'a']){
                        ans = max(ans, j-i+1);
                    } else {
                        changed = false;
                        break;
                    }

                    // cout<<ch << " -> freq -> "<< freq[ch-'a']<<" | ";
                }

                if(!changed){
                    ans = tempAns;
                }
                // cout<<endl;

            }
        }

        return ans;
    }
};