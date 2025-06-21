class Solution {
private:
    vector<int> prevSmallerElement(vector<int>& heights){
        int n = heights.size();
        vector<int> result(n);
        stack<int> st;
        st.push(-1);

        for(int i = 0; i<n; i++){
            while(st.top()!=-1 && heights[i] <= heights[st.top()]){
                st.pop();
            }
            result[i] = st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> nextSmallerElement(vector<int>& heights){
        int n = heights.size();
        vector<int> result(n);
        stack<int> st;
        st.push(-1);

        for(int i = n-1; i>=0; i--){
            while(st.top()!=-1 && heights[i] <= heights[st.top()]){
                st.pop();
            }
            result[i] = st.top();
            st.push(i);
        }
        return result;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = INT_MIN;
        vector<int> prev = prevSmallerElement(heights);
        vector<int> next = nextSmallerElement(heights);

        for(int i = 0;i<n;i++){
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] -1;
            int l = heights[i];
            ans = max(ans, l*b);
        }
        return ans;
    }
};