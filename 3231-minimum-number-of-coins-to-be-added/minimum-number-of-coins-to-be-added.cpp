class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int reach = 0, cnt = 0;

        for(int i= 0; i<coins.size(); i++){
            while(coins[i] > reach+1){
                reach = 2 * reach + 1;
                cnt++;
            }
            reach+=coins[i];

            if(reach>=target){
                break;
            }
        }

        while (reach < target) {
            reach = 2 * reach + 1;
            cnt++;
        }

        return cnt;
    }
};