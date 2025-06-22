class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int ans = 0;

        for(const char &ch : s){
            if(ch =='('){
                st.push(ch);
                ans++;
            } else {
                if(!st.empty()){
                    st.pop();
                    ans--;
                } else {
                    ans++;
                }
            }
        }
        return ans;
    }
};