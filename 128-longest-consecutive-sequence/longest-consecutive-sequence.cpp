class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> st;
        for(const int &num: nums) st.insert(num);

        for(const int &num: st) {
            if(st.find(num-1) == st.end()) {
                int curr = num;
                int cnt = 1;

                while(st.find(curr+1) != st.end()) {
                    cnt++;
                    curr++;
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};