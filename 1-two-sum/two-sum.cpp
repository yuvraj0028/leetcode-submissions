class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int,int> mp;

        // for(int i = 0;i<nums.size();i++){
        //     int rem = target - nums[i];

        //     if(mp.find(rem) != mp.end()){
        //         return {mp[rem],i};
        //     }

        //     mp[nums[i]] = i;
        // }

        int i = 0;
        int j = 1;

        while(i<nums.size() && j<nums.size()){
            if(nums[i] + nums[j] == target && i!=j){
                return {i,j};
            }
            else if(j<nums.size()-1){
                j++;
                continue;
            }

            i++;
            j=1;
        }

        return  {};
    }
};