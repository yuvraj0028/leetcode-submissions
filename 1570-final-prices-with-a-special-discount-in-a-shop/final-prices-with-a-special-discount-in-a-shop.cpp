class Solution {
public:
    vector<int> finalPrices(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--){

            while(!st.empty() && arr[i]<st.top()) st.pop();
            
            if(st.empty()){
                ans[i] = arr[i];
                st.push(arr[i]);
            } else {
                ans[i] = arr[i] - st.top();
                st.push(arr[i]);
            }
        }

        return ans;
    }
};