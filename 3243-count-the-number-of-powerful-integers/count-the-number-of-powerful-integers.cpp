#define ll long long

int n, m, limit;
string s, num;
vector<vector<ll>> dp;

class Solution {
public:
    ll DP(int pos = 0, bool tig = 1) {
        if (n < m) return 0;
        if (pos == n) return 1;
        if (dp[pos][tig] != -1) return dp[pos][tig];
        ll ans = 0, digLim = tig ? num[pos] - '0' : 9;
        for (int dig = 0; dig <= min((int)digLim, limit); dig++) if (pos < n - m || dig == s[pos - n + m] - '0') ans += DP(pos + 1, tig && (dig == digLim));
        return dp[pos][tig] = ans;
    }

    long long DP(string _num) {
        num = _num;
        n = num.size();
        dp = vector<vector<ll>> (n, vector<ll> (2, -1));
        return DP();
    }

    long long numberOfPowerfulInt(long long start, long long finish, int _limit, string _s) {
        s = _s, m = s.size(), limit = _limit;
        return DP(to_string(finish)) - DP(to_string(start - 1));
    }
};