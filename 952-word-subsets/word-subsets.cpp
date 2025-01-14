class Solution {
private:
    bool isSubset(vector<int> &freq, vector<int> &temp){
        for(int i = 0; i<26; i++){
            if(temp[i] < freq[i]){
                return false;
            }
        }

        return true;
    }

public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq2(26);
        vector<string> ans;

        for(const string &str : words2){

            int temp[26] = {0};

            for(const char &ch : str){
                int index = ch-'a';
                temp[index]++;
                freq2[index] = max(temp[index], freq2[index]);
            }
        }

        for(const string &str : words1){
            
            vector<int> temp(26);

            for(const char &ch : str){
                temp[ch-'a']++;
            }

            if(isSubset(freq2, temp)){
                ans.push_back(str);
            }
        }

        return ans;

    }
};