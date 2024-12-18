class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);

        // monotonic stack to store next smaller element
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            
            // pop element until we find a number which can be discounted
            while(!st.empty() && prices[i]<st.top()) st.pop();
            
            // check if stack is empty directly assign the element
            // else get the doscount and push to stack
            if(st.empty()){
                ans[i] = prices[i];
                st.push(prices[i]);
            } else {
                ans[i] = prices[i] - st.top();
                st.push(prices[i]);
            }
        }

        return ans;
    }
};