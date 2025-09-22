class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxFreq = 0, cnt = 0;
        for(const int &i : nums){
            freq[i]++;
            maxFreq = max(maxFreq, freq[i]);
        }

        for(const auto &i : freq){
            if(maxFreq == i.second){
                cnt+=i.second;
            }
        }

        return cnt;
    }
};