class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();

        int onesCnt = 0;
        bool prevOneFound = false;

        for(int i = 0; i<n; i++){
            if(s[i]=='1'){
                if(prevOneFound) return false;
                onesCnt++;
            } else {
                if(onesCnt){
                    prevOneFound = true;
                }
            }
        }

        return true;
    }
};