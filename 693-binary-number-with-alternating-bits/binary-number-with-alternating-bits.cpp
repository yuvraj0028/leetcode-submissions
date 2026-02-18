class Solution {
public:
    bool hasAlternatingBits(int n) {
        string st = "";

        while(n>0){
            int bit = n%2;
            st.push_back('0'+bit);
            n/=2;
        }

        for(int i = 0; i<st.size()-1; i++){
            if(st[i] == st[i+1]) return false;
        }
        
        return true;
    }
};