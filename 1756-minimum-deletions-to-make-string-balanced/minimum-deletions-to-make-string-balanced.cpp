class Solution {
public:
    int minimumDeletions(string s) {
        int cnt = 0;
        stack<char> st;

        for(int i = s.size() - 1;i>=0;i--){
            if(!st.empty() && s[i] == 'b' && st.top() == 'a'){
                st.pop();
                cnt++;
            } else {
                st.push(s[i]);
            }
        }

        return cnt;
    }
};