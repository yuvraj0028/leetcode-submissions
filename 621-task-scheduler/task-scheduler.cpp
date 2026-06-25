class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> freq;
        for(const char &ch: tasks) freq[ch-'A']++;
    
        priority_queue<int> pq;

        for(const auto [k,v]: freq) {
            pq.push(v);
        }

        int time = 0;
        while(!pq.empty()) {
            vector<int> temp;            
            int cycle = n+1;

            for(int i = 0; i<cycle; i++) {
                if(!pq.empty()) {
                    int top = pq.top(); pq.pop();
                    if (top - 1 > 0) {
                        temp.push_back(top - 1);
                    }
                    time++;
                } else if(!temp.empty()) {
                    time++;
                } else {
                    break;
                }
            }

            for(const auto &i : temp) {
                pq.push(i);
            }
        }

        return time;
    }
};