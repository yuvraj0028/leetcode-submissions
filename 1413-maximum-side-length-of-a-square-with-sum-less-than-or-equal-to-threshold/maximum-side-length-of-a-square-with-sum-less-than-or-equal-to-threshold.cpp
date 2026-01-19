class Solution {

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;

        // calc prefix sum
        vector<vector<int > > prefix(n+1, vector<int>(m+1,0));

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                prefix[i][j] = mat[i-1][j-1] + 
                               prefix[i][j-1] + 
                               prefix[i-1][j] - 
                               prefix[i-1][j-1];
            }
        }

        // bin search for finding ans

        int s = 0;
        int e = min(n,m);

        while(s<=e){
            int mid = (s+e)/2;
            bool found = false;

            for(int i = mid; i<=n && !found; i++){
                for(int j = mid; j<=m; j++){
                    int sum = prefix[i][j] - 
                              prefix[i][j-mid] - 
                              prefix[i-mid][j] + 
                              prefix[i-mid][j-mid];
                
                    if(sum<=threshold){
                        found = true;
                        break;
                    }

                }
            }

            if(found){
                ans = mid;
                s=mid+1;
            } else {
                e=mid-1;
            }
        }

        return ans;
    }
};