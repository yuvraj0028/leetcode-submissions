class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26);
        int evenMin = INT_MAX, oddMax = 0;

        for(const char &i : s){
            freq[i-'a']++;
        }

        for(const int &i : freq){
            if(i>0){
                if(i%2 == 0){
                    evenMin = min(evenMin, i);
                } else {
                    oddMax = max(oddMax, i);
                }
            }
        }

        return oddMax - evenMin;
    }
};