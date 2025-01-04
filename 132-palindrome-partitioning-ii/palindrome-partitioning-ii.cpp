class Solution {
private:
    bool isPalindrome(string &s){
        int start = 0;
        int end = s.size() - 1;
        while(start <= end){
            if(s[start++] != s[end--])
                return false;
        }

        return true;
    }
    int findMinCut(string &s, vector<int> &v, int i){
        if(i == s.size()) return 0;

        if(v[i] !=-1) return v[i];

        string temp = "";
        int mini = INT_MAX;

        for(int j = i; j<s.size(); j++){
            temp+=s[j];

            if(isPalindrome(temp)){
                int cost = 1 + findMinCut(s, v, j+1);
                mini = min(mini, cost);
            }
        }

        return v[i] = mini;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> v(n+1, -1);
        return findMinCut(s, v, 0) - 1;
    }
};