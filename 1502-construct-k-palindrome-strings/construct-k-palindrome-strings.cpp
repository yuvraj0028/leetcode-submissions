class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> M;
        int Single = 0;

        // Count frequencies of each character
        for (char c : s) {
            M[c]++;
        }

        // Count pairs and singles
        for (auto &[ch, freq] : M) {
            if (freq % 2 == 1) {
                Single++; // Count remaining single characters
            }
        }
        return (Single <= k && k <= s.size());
    }
};