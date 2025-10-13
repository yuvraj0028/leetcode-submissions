class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string prevSorted = "";

        for (const string &word : words) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());  // sort characters of the word

            if (sortedWord != prevSorted) {  // not an anagram of previous kept word
                result.push_back(word);
                prevSorted = sortedWord;
            }
        }

        return result;
    }
};
