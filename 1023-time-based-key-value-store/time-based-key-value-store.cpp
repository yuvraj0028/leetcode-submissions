// class IntComparator{
// public:
//     bool operator()(const pair<string, int> &a, const pair<string, int> &b) const {
//         if (a.second != b.second) {
//             return a.second < b.second;
//         }
//         return a.first < b.first;
//     }
// };

class TimeMap {
private:
    // unordered_map<string, multiset<pair<string, int>, IntComparator> > store;
    unordered_map<string, vector<pair<string, int> > > store;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        pair<string, int> newPair = {value, timestamp};
        store[key].push_back(newPair);
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()) return "";

        int s = 0;
        int e = store[key].size() - 1;

        string res = "";

        while(s<=e) {
            int mid = (e-s)/2 + s;

            if(store[key][mid].second <= timestamp) {
                res = store[key][mid].first;
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 
 */