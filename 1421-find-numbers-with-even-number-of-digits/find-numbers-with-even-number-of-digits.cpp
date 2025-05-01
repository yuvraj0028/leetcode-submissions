class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;

        for(const int &i : nums){
            string temp = to_string(i);
            if(temp.size() % 2 == 0) cnt++;
        }

        return cnt;
    }
};