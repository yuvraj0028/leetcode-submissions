class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int start = 0, end = n-1;
        int colorStart = colors[0];
        int colorEnd = colors[n-1];

        int ans = -1;
    
        while(start <= end) {
            if(colors[start] != colorStart) {
                ans = max(ans, abs(0 - start));
            }
            
            if(colors[end] != colorStart) {
                ans = max(ans, abs(0 - end));
            }
            
            if(colors[start] != colorEnd) {
                ans = max(ans, abs(n-1-start));
            }
            
            if(colors[end] != colorEnd) {
                ans = max(ans, abs(n-1-end));
            }

            start++;
            end--;
        }

        return ans;
    }
};