class Solution {
private:
    int getMinDist(int a, int b, int n) {
        int d = abs(a-b);
        return min(d, abs(n-d));
    }
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int > > mp;
        
        for(int i = 0; i<nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> res;

        for(int i = 0; i<queries.size(); i++) {
            int qIdx = queries[i];
            int val = nums[qIdx];

            const vector<int> &sortedList = mp[val];
            int size = sortedList.size();
            
            if(size<=1) {
                res.push_back(-1);
                continue;
            }
            
            auto itr = lower_bound(sortedList.begin(), sortedList.end(), qIdx);
            int pos = distance(sortedList.begin(), itr);

            int left = sortedList[(pos + size - 1) % size];
            int right = sortedList[(pos + 1) % size];

            res.push_back(min(getMinDist(qIdx, left, nums.size()), getMinDist(qIdx, right, nums.size())));
        }

        return res;
    }
};