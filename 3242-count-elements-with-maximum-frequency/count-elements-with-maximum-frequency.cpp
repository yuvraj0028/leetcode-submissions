#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        int maxFreq = 0;   // Stores the maximum frequency found so far.
        int totalCount = 0; // Stores the sum of frequencies for elements with maxFreq.

        // Single pass through the input array.
        for (const int& num : nums) {
            // Increment the frequency of the current number.
            freq[num]++;
            int currentFreq = freq[num];

            // Case 1: We found a new, higher maximum frequency.
            if (currentFreq > maxFreq) {
                maxFreq = currentFreq;
                // Reset the total count. The count is now just the frequency
                // of this single element which has the new max frequency.
                totalCount = currentFreq; 
            }
            // Case 2: We found another element with the same maximum frequency.
            else if (currentFreq == maxFreq) {
                // Add this element's frequency to the total count.
                totalCount += currentFreq;
            }
            // Case 3 (currentFreq < maxFreq) requires no action.
        }

        return totalCount;
    }
};