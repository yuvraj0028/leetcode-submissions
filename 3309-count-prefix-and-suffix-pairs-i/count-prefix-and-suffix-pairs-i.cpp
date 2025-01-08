class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();

        for(int i = 0; i<n-1; i++){
            
            string pattern = words[i];
            int patternSize = pattern.size();

            for(int j = i+1; j<n; j++){
                string word = words[j];
                int wordSize = word.size();

                if(patternSize > wordSize) continue;

                if(word.find(pattern) == 0 && (word.rfind(pattern) == wordSize - patternSize)){
                    ans++;
                }
            }
        }

        return ans;
    }
};