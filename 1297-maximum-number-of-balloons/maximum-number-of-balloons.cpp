class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        int mini = INT_MAX;

        for(const auto &ch: text) {
            if(ch == 'b' || ch == 'a' || ch == 'l' || ch == 'l' || ch == 'o' || ch == 'o' || ch == 'n') {
                mp[ch]++;
            }
        }

        // for(const auto [k,v] : mp) {
        //     cout<<k<<" -> "<<v<<endl;
        // }

        if (mp.size() != 5 || mp['l'] < 2 || mp['o'] < 2) {
            return 0;
        }

        mp['l'] = mp['l']/2; 
        mp['o'] = mp['o']/2; 

        for(const auto [k,v] : mp) {
            mini = min(v, mini);
        }

        return mini != INT_MAX ? mini : 0;
    }
};