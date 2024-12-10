class Solution {
public:
    int maximumLength(string s) {
        int n= s.size();

        unordered_map<string,int> mp;

        int ans = -1;
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n+1;j++){
                string temp = s.substr(i,j-i);

                sort(temp.begin(),temp.end());

                if(temp[0] != temp[temp.size()-1])
                    continue;

                mp[temp]++;


            }
        }

        for(auto &it : mp){
            if(it.second>=3){
                if(ans<(int)it.first.size()){
                    ans = (int)it.first.size();
                }
            }
        }

        return ans;
    }
};