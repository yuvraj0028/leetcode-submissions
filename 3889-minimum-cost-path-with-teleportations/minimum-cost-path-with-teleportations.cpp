class Solution {
public:
    int minCost(vector<vector<int>> &grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prev(m * n, vector<int>(2, INT_MAX)), curr(m * n, vector<int>(2, INT_MAX)), tmp(m * n, vector<int>(2, INT_MAX));
        vector<int> suff(m * n, INT_MAX);
        prev[0][1] = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                prev[i * n + j][0] = grid[i][j];
                if(i - 1 >= 0) prev[i * n + j][1] = min(prev[i * n + j][1], 
                grid[i][j] + prev[(i - 1) * n + j][1]);
                if(j - 1 >= 0) prev[i * n + j][1] = min(prev[i * n + j][1], 
                grid[i][j] + prev[i * n + j - 1][1]);
            }
        }
        for(int l = 1; l <= k; l++) {
            for(int i = 0; i < m * n; i++) {
                tmp[i][0] = prev[i][0];
                tmp[i][1] = prev[i][1];
            }
            sort(tmp.begin(), tmp.end());

            for(int i = m * n - 1, s = INT_MAX; i >= 0; i--) {
                s = min(s, tmp[i][1]);
                suff[i] = s;
            }
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    int u = -1, v = m * n;
                    while(v > u + 1) {
                        int mid = (u + v) / 2;
                        if(tmp[mid][0] >= grid[i][j]) v = mid;
                        else u = mid;
                    }

                    curr[i * n + j][0] = grid[i][j];

                    curr[i * n + j][1] = min(prev[i * n + j][1], suff[v]);

                    if(i - 1 >= 0) curr[i * n + j][1] = min(curr[i * n + j][1], 
                    curr[(i - 1) * n + j][1] + grid[i][j]);

                    if(j - 1 >= 0) curr[i * n + j][1] = min(curr[i * n + j][1], 
                    curr[i * n + j - 1][1] + grid[i][j]);
                }
            }
            prev = curr;
        }
        return prev[m * n - 1][1];
    }
};