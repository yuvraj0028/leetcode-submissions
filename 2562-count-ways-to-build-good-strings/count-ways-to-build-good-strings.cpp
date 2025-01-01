#define MOD 1000000007

class Solution {
private:
    // int dp[100001];
    // int countStrings(int minLength, int maxLength, int numZeros, int numOnes, int length){
    //     if(length > maxLength){
    //         return 0;
    //     }

    //     if(dp[length] != -1) return dp[length];

    //     int got = 0;

    //     if(length>=minLength && length <= maxLength){
    //         got = 1;
    //     }

    //     int ones = countStrings(minLength, maxLength, numZeros, numOnes, length+numOnes) % MOD;
    //     int zeros = countStrings(minLength, maxLength, numZeros, numOnes, length+numZeros) % MOD;

    //     return dp[length] = (got + ones + zeros) % MOD;
    // }

    int countStringsTabulation(int minLength, int maxLength, int numZeros, int numOnes){
        vector<int> dp(100001 + maxLength);

        for(int length = maxLength; length>= 0; length--){
            int got = 0;

            if(length>=minLength && length <= maxLength){
                got = 1;
            }

            int ones = dp[length+numOnes] % MOD;
            int zeros = dp[length+numZeros] % MOD;

            dp[length] = (got + ones + zeros) % MOD;
        }

        return dp[0];
    }
public:
    int countGoodStrings(int minLength, int maxLength, int numZeros, int numOnes) {
        // memset(dp,-1, sizeof(dp));
        return countStringsTabulation(minLength, maxLength, numZeros, numOnes);
    }
};