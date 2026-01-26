class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        int minRes = INT_MAX;
        sort(arr.begin(), arr.end());
        vector<vector<int > > ans;

        for(int i = 0; i<n-1; i++){
            int res = abs(arr[i] - arr[i+1]);
            
            if(res < minRes){
                ans.clear();
                ans.push_back({arr[i], arr[i+1]});
                minRes = res;
            } else if(res == minRes){
                ans.push_back({arr[i], arr[i+1]});
            }
        }

        return ans;
    }
};