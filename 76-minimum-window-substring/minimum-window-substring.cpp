class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        
        int left = 0;
        int n = s.size();
        int startIndex = 0;
        int minLen = INT_MAX;
        int remainingCount = t.size();
        unordered_map<char,int> freq;
        
        for(const char &ch : t) freq[ch]++;

        for(int right = 0; right<n; right++){
            char ch = s[right];
            if(freq[ch] > 0){
                remainingCount--;
            }

            freq[ch]--;

            while(!remainingCount){
                int winSize = right - left + 1;

                if(winSize < minLen){
                    minLen = winSize;
                    startIndex = left;
                }

                freq[s[left]]++;

                if(freq[s[left]]>0){
                    remainingCount++;
                }

                left++;
            }
        }

        return  minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};