class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int n = meetings.size();
        int ans = 0;
       
        int first = meetings[0][0];
        int last = meetings[0][1];

        for(int i = 1; i<n; i++){
            int curr_first = meetings[i][0];
            int curr_last = meetings[i][1];

            if(curr_first > last){
                ans += curr_first - last -1;
            }

            last = max(last, curr_last);
        }


        if(first != 1){
            ans+=first - 1;
        }

        if(last < days){
            ans+=days-last;
        }

        return ans;
    }
};