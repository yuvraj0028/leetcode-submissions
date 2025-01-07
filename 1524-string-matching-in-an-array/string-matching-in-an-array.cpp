class Solution {
private:
    vector<vector<int > > computeLPS(vector<string> &words){
        vector<vector<int > > LPS;
        for(const string &word : words){
            int i = 1, j = 0;
            int size = word.size();

            vector<int> currLPS(size);

            while(i < size){
                if(word[i] == word[j]){
                    currLPS[i] = j + 1;
                    i++;
                    j++;
                } else if(j > 0){
                    j = currLPS[j-1];
                } else {
                    i++;
                }
            }

            LPS.push_back(currLPS);
        }

        return LPS;
    }

    bool stringMatcher(string &text, string &pattern, vector<int> &LPS){
        int textSize = text.size();
        int patternSize = pattern.size();
        int i = 0;
        int j = 0;

        while(i<patternSize && j<textSize){
            if(text[j] == pattern[i]){
                i++;
                j++;
            }

            if(i == patternSize){
                return true;
            }

            if(j<textSize && pattern[i] != text[j]){
                if(i>0){
                    i = LPS[i-1];
                } else {
                    j++;
                }
            }
        }

        return false;
    }

    static bool comparator(const string &word1, const string &word2){
        return word1.size() <= word2.size();
    }

public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;

        sort(words.begin(), words.end(), comparator);

        vector<vector<int > > LPS = computeLPS(words);

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(stringMatcher(words[j], words[i], LPS[i])){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;

    }
};