class Solution {
private:
    bool isValid(string &prefix, string &word){
        int n = prefix.size();
        int m = word.size();

        if(n > m) return false;

        int i = 0, j = 0;

        while(i<n){
            if(prefix[i] != word[j]){
                return false;
            }
            i++;
            j++;
        }

        return true;
    }
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        
        for(string word : words){
            if(isValid(pref,word)){
                count++;
            }
        }

        return count;
    }
};