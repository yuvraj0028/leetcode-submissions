#define ll long long

class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        int n = diff.size();
        
        ll prefix_sum = 0;
        ll min_prefix = 0;
        ll max_prefix = 0;

        for(int i = 0; i<n; i++){
            prefix_sum += diff[i];
            min_prefix = min(min_prefix, prefix_sum);
            max_prefix = max(max_prefix, prefix_sum);
        }

        ll min_x = lower - min_prefix;
        ll max_x = upper - max_prefix;

        if(max_x < min_x){
            return 0;
        }

        return max_x - min_x + 1;
    }
};