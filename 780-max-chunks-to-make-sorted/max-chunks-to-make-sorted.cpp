class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        vector<int> aux = arr;
        sort(aux.begin(), aux.end());

        int sum1 = 0, sum2 = 0, chunk = 0;

        for(int i = 0;i<n;i++){
            sum1+=arr[i];
            sum2+=aux[i];

            if(sum1 == sum2){
                chunk++;
            }
        }

        return chunk;
    }
};