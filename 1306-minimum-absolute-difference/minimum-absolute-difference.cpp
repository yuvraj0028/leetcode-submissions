class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        int minRes = INT_MAX;
        unordered_map<int, vector<vector<int> > > mp; 
        sort(arr.begin(), arr.end());

        for(int i = 0; i<n-1; i++){
            int res = abs(arr[i] - arr[i+1]);
            mp[res].push_back({arr[i], arr[i+1]});
            minRes = min(res, minRes);
        }

        return mp[minRes];
    }
};