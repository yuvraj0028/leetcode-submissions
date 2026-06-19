class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int start = 0;
        int maxi = INT_MIN;

        for(int i = 0; i<gain.size(); i++) {
            int alt = start + gain[i];
            maxi = max(maxi, alt);
            start = alt;
        }
        return maxi >= 0 ? maxi : 0;
    }
};