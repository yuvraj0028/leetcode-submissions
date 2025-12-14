class Solution {
private:
    vector<int> nextSmallerElement(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for(int i = n-1;i>=0;i--){
            while(st.top() != -1 && arr[i] <= arr[st.top()]){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for(int i = 0; i<n; i++){
            while(st.top() != -1 && arr[i] <= arr[st.top()]){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(); 
        vector<int> prev = prevSmallerElement(heights);
        vector<int> next = nextSmallerElement(heights);

        int area = 0;
        for(int i = 0;i<n;i++){
            if(next[i] == -1){
                next[i] = n;
            }

            int b = next[i] - prev[i] - 1;
            int l = heights[i];

            area = max(area, l*b);
        }

        return area;
    }
};