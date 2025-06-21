class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0;
        unordered_map<char,int> mp;
        priority_queue<int> pq;

        for(const char &ch : tasks) mp[ch]++;
        for(const auto &[k,v] : mp) pq.push(v);
        
        while(!pq.empty()){
            int time = 0;
            vector<int> temp;
            for(int i = 0;i<n+1; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top() -1);
                    pq.pop();
                    time++;
                }
            }
            for(const int &i : temp)
                if(i) pq.push(i);

            res += pq.empty() ? time : n+1;
        }
        return res;
    }
};