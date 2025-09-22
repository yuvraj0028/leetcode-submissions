class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        vector<int> freq(101);
        int maxFreq = 0;
        int totalCount = 0;

        for (const int& num : nums) {
            freq[num]++;
            int currentFreq = freq[num];

            if (currentFreq > maxFreq) {
                maxFreq = currentFreq;
                totalCount = currentFreq; 
            }
            else if (currentFreq == maxFreq) {
                totalCount += currentFreq;
            }
        }
        return totalCount;
    }
};