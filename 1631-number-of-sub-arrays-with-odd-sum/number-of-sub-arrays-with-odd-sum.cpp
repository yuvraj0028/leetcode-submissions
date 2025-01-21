#define MOD 1000000007

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int oddCount = 0;
        int evenCount = 1;
        int totalSubArrays = 0;
        int sum = 0;
        int n = arr.size();

        for(int i = 0;i<n;i++){
            sum+=arr[i];
            if(sum%2 == 0){
                totalSubArrays = (totalSubArrays%MOD + oddCount%MOD)%MOD;
                evenCount++; 
            } else {
                totalSubArrays = (totalSubArrays%MOD + evenCount%MOD)%MOD;
                oddCount++;
            }
        }

        return totalSubArrays % MOD;
    }
};