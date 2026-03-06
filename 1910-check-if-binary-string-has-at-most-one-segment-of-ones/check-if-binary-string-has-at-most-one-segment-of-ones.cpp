class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();

        // check leading 0
        int zerosCnt = 0, onesCnt = 0;
        bool prevOneFound = false;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                break;
            }
            zerosCnt++;
        }

        if(zerosCnt > 0) return false;

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