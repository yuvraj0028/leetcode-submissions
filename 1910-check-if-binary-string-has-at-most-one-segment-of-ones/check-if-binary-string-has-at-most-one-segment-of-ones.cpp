class Solution {
public:
    bool checkOnesSegment(string s) {
        // check leading zeros
        int zerosCnt = 0;
        int n = s.size();

        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                break;
            }

            zerosCnt++;
        }

        if(zerosCnt > 0) return false;

        string temp = "";
        unordered_map<string,int> mp;        

        for(int i = 0; i<n; i++){
            if(s[i] == '1'){
                temp+=s[i];
            }
            
            else {
                if(temp.size() > 0){
                    mp[temp]++;
                    temp="";
                }
            }
        }

        if(temp.size()>0){
            mp[temp]++;
        }

        if(mp.size() > 1){
            return false;
        }

        for(const auto [k,v] : mp){
            // cout<<k<<" -> "<<v<<endl;
            if(v == 1) return true;
        }

        return false;
    }
};