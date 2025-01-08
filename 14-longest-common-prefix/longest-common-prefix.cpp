class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string word = strs[0];

        for(int i = 1; i<n; i++){
            string temp = "";
            string tempWord = strs[i];

            int j = 0, k = 0;

            while(j < word.size() && k < tempWord.size()){
                if(word[j] == tempWord[k]){
                    temp+=word[j];
                    j++; k++;
                } else {
                    break;
                }
            }

            word = temp;
        }

        return word;
    }
};