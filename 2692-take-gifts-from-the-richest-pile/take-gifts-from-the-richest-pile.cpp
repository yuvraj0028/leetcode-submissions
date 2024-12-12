#define ll long long

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        ll ans = 0;
        
        // defining max heap and inserting "gifts" value
        priority_queue<int, vector<int> > pq(gifts.begin(),gifts.end());

        // traversing until k becomes 0
        while(k--){
            int top = pq.top(); pq.pop();
            // finding the square root of top(max) element in the heap
            int sq = sqrt(top);
            // finding the floor value of sq
            int flr = floor(sq);
            // pushing the floor value to heap again to calculate the ans
            pq.push(flr);
        }
        
        // calculating the sum of elements in heap
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};