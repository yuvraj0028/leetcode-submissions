class Solution {
public:
    int trap(vector<int>& height) {
        // int ans = 0;
        // int n = height.size();
        // vector<int> left(n), right(n);

        // left[0] = height[0];
        // for(int i = 1; i<n; i++) {
        //     left[i] = max(left[i-1], height[i]);
        // }

        // right[n-1] = height[n-1];
        // for(int i = n-2; i>=0; i--) {
        //     right[i] = max(right[i+1], height[i]);
        // }

        // for(int i = 0; i<n; i++) {
        //     ans+=min(left[i], right[i]) - height[i];
        // }

        // return ans;


        // optimized two pointer approach
        int ans = 0;
        int n = height.size();
        int left = 0, right = n-1;
        int leftMax = 0, rightMax = 0;

        while(left < right) {
            // Case A if height left <= height right
            if(height[left] <= height[right]) {
                // if height left is > leftMax then update leftMax
                // water cannot be store here
                if(height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    ans += leftMax - height[left];
                }
                left++;
            } else {
                // case B if height left > height right
                if(height[left] > height[right]) {
                    // if height right is > rightMax then update rightMax
                    // water cannot be store here
                    if(height[right] >= rightMax) {
                        rightMax = height[right];
                    } else {
                        ans += rightMax - height[right];
                    }
                    right--;
                }
            }
        }

        return ans;
    }
};