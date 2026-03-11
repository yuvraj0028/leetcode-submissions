class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int s = 0, e = n-1;
        int ans = INT_MIN;

        while(s<=e) {
            if(height[s]<=height[e]){
                ans = max(ans, (e-s)*(height[s]));
                s++;
            } else {
                ans = max(ans, (e-s)*(height[e]));
                e--;
            }
        }

        return ans;
    }
};