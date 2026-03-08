class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;


        set<int> st;
        for(const int &i : nums){
            st.insert(i);
        }

        vector<int> temp(st.begin(), st.end());
        int n = temp.size();
        int cnt = 1;
        int ans = cnt;

        for(int i = 0; i<n-1; i++){
            int curr = temp[i];
            int next = temp[i+1];

            if(curr+1 == next){
                cnt++;
            } else {
                cnt = 1;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};