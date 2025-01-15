class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        
        int ans = 0;

        for(int i = 0; i<n; i++){
            while(!st.empty() && height[st.top()] < height[i]){
                int top = height[st.top()]; st.pop();

                if(st.empty()) break;

                int dist = i - st.top() - 1;
                int minHeight = min(height[st.top()], height[i]) - top;

                ans += dist * minHeight;
            }

            st.push(i);
        }

        return ans;
    }
};