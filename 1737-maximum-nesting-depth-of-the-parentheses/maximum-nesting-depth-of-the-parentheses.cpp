class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int n = s.size();

        int maxi = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(s[i]);
                int size = st.size();
                maxi = max(maxi, size);

            } else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }
            }
        }

        return maxi;
    }
};