class Solution {
private:
    bool isPalindrome(string &s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--])
                return false;
        }

        return true;
    }

    void findPartitions(vector<vector<string > > &ans, vector<string> &v, string &s, int i){
        if(i==s.size()){
            ans.push_back(v);
            return;
        }
    
        for(int index = i; index<s.size(); index++){
            if(isPalindrome(s,i,index)){
                v.push_back(s.substr(i, index - i + 1));
                findPartitions(ans, v, s, index+1);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;

        findPartitions(ans, v, s, 0);

        return ans;
    }
};