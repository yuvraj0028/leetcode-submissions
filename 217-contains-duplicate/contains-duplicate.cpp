class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        
        for(const int &num: nums) {
            if(st.count(num)){
                return true;
            }
            st.insert(num);
        }

        return false;
    }
};