#define MOD 1000000007
#define ll long long

class Solution {
public:
    int numWays(string s) {
        int n = s.size();
        ll ones = 0;

        for(int i = 0; i<n; i++){
            ones += s[i] - '0';
        }

        if(ones == 0) return (int)((((n-1LL) * (n-2LL)) / 2) % MOD);

        if(ones% 3 != 0) return 0;

        ll oneThird = ones/3;

        ones = 0;
        ll a = 0, b = 0;

        for(int i = 0; i<n;i++){
            ones+=s[i]-'0';

            if(ones == oneThird) a++;
            if(ones == 2*oneThird) b++;
        }

        return (int)((a * b)%MOD);
    }
};