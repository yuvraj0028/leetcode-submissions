class Solution {
private:
    static bool comparator(const vector<int> &tripA, const vector<int> &tripB) {
        int fromTripA = tripA[1];
        int toTripA = tripA[2];

        int fromTripB = tripB[1];
        int toTripB = tripB[2];

        if(fromTripA == fromTripB){
            return toTripA < toTripB;
        }

        return fromTripA < fromTripB;
    }

public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), comparator);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int > > > pq;
        
        int prefix = 0;

        for(int i = 0;i<trips.size(); i++){
            while(!pq.empty() && pq.top().first<=trips[i][1]){
                prefix-=pq.top().second;
                pq.pop();
            }

            pq.push({trips[i][2], trips[i][0]});
            prefix+=trips[i][0];

            if(prefix > capacity) return 0;
        }

        return 1;
    }
};