class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int score = INT_MIN;

        int maxi = values[0];

        for(int i = 1; i<n; i++){
            int curr = values[i] - i;
            int tempScore = maxi + curr;

            score = max(score, tempScore);

            maxi = max(maxi, values[i]+i);
        }

        return score;
    }
};