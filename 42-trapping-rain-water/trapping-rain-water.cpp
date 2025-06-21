class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;

        for(int i = 0;i<height.size();i++){
            while(!st.empty() && height[st.top()] < height[i]){
                int top = height[st.top()];
                st.pop();
                if(st.empty()) break;
                int h = min(height[st.top()],height[i]) - top;
                int d = i - st.top() - 1;
                int area = h*d;
                ans += area;
            }
            st.push(i);
        }
        return ans;
    }
};