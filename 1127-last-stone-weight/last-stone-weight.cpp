class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq(stones.begin(), stones.end());

        while(pq.size() > 1) {
            int top1 = pq.top(); pq.pop();
            int top2 = pq.top(); pq.pop();

            int diff = abs(top1 - top2);

            if(diff) {
                pq.push(diff);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};