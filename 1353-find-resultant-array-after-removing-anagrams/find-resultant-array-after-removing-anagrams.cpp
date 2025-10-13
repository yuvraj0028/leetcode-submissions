class Solution {
private:
    bool checkAnagrams(string &s1, string &s2){
        if(s1.size() != s2.size()) return false;
        multiset<char> ms;

        for(const char &ch : s1){
            ms.insert(ch);
        }

        for(const char &ch : s2){
            auto it = ms.find(ch);
            if(it != ms.end()){
                ms.erase(it);
            }
        }

        return ms.size() == 0;
    }

public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        
        for(int i = 1; i<n; i++){
            string s1 = words[i-1];
            string s2 = words[i];

            if(checkAnagrams(s1, s2)){
                swap(words[i-1], words[i]);
                words[i-1] = "";
            }
        }

        vector<string> ans;
        for(const string &s : words)
            if(s!="") ans.push_back(s);
   
        return ans;
    }
};