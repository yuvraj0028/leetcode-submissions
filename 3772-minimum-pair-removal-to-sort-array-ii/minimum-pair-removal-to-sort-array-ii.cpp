class Solution {
public:
    typedef long long ll;
    int minimumPairRemoval(vector<int>& nums1) {
        int n = nums1.size();
        vector<ll> nums(n,0);
        for(int i=0;i<n;i++){
            nums[i] = nums1[i];
        }

        vector<int> nextIndex(n),prevIndex(n);

        for(int i=0;i<n;i++){
            nextIndex[i] = i+1;
        }

        for(int i=0;i<n;i++){
            prevIndex[i] = i-1;
        }
        set<pair<ll,int>> pairSumSet;
        int badPairCount = 0;

        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i+1])badPairCount++;

            pairSumSet.insert({nums[i]+nums[i+1], i});
        }

        int mergeOperations = 0;

        while(badPairCount > 0){

            auto it = pairSumSet.begin();
            int currIdx = it->second;
            int nextIdx = nextIndex[currIdx];
            int prevIdx = prevIndex[currIdx];

            int nextNextIdx = nextIndex[nextIdx];

            pairSumSet.erase(it);

            if(nums[currIdx] > nums[nextIdx])badPairCount--;

            if(prevIdx >= 0){
                if(nums[prevIdx] > nums[currIdx]) badPairCount--;
                if(nums[prevIdx] > nums[currIdx] + nums[nextIdx]) badPairCount++;
                pairSumSet.erase({nums[prevIdx] + nums[currIdx], prevIdx});
            }

            if(nextNextIdx < n){
                if(nums[nextIdx] > nums[nextNextIdx]) badPairCount--;
                if(nums[currIdx] + nums[nextIdx] > nums[nextNextIdx]) badPairCount++;
                pairSumSet.erase({nums[nextIdx] + nums[nextNextIdx], nextIdx});
            }

            nums[currIdx] = nums[currIdx] + nums[nextIdx];

            nextIndex[currIdx] = nextNextIdx;
            if(nextNextIdx < n) prevIndex[nextNextIdx] = currIdx;

            if(prevIdx >= 0){
                pairSumSet.insert({nums[prevIdx] + nums[currIdx], prevIdx});
            }

            if(nextNextIdx < n){
                pairSumSet.insert({nums[currIdx] + nums[nextNextIdx], currIdx});
            }

            mergeOperations++;
        }
        return mergeOperations;
    }
};