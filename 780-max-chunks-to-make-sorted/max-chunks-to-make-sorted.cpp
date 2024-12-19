class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxi = INT_MIN;
        int chunk = 0;
        
        for(int i = 0;i<n;i++){
            maxi = max(arr[i], maxi);
            if(maxi == i) chunk++;
        }

        return chunk;
    }
};