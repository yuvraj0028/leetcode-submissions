class Solution {
private:
    vector<int> prevSmallerElements(vector<int>& heights){
        int n = heights.size();
        vector<int> vec(n);

        stack<int> st;

        st.push(-1);

        for(int i = 0;i<n;i++){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }

            vec[i] = st.top();
            st.push(i);
        }

        return vec;
    }

    vector<int> nextSmallerElements(vector<int>& heights){
        int n = heights.size();
        vector<int> vec(n);

        stack<int> st;

        st.push(-1);

        for(int i = n-1;i>=0;i--){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }

            vec[i] = st.top();
            st.push(i);
        }

        return vec;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> prev = prevSmallerElements(heights);
        vector<int> next = nextSmallerElements(heights);

        int ans = -1;

        for(int i =0; i<n; i++){
            int length = heights[i];

            if(next[i] == -1){
                next[i] = n;
            }

            int breath = next[i] - prev[i] - 1;

            ans = max(ans, length * breath);
        }

        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int > > mat(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mat[i][j] = matrix[i][j] - '0';
            }
        }

        int area = largestRectangleArea(mat[0]);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] != 0){
                    mat[i][j]+=mat[i-1][j];
                } else {
                    mat[i][j] = 0;
                }
            }

            int tempArea = largestRectangleArea(mat[i]);

            area = max(area, tempArea);
        }

        return area;
    }
};