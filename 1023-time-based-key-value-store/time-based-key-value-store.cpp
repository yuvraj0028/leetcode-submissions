class IntComparator{
public:
    bool operator()(const pair<string, int> &a, const pair<string, int> &b) const {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};

class TimeMap {
private:
    unordered_map<string, multiset<pair<string, int>, IntComparator> > store;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        pair<string, int> newPair = {value, timestamp};
        store[key].insert(newPair);
    }
    
    string get(string key, int timestamp) {
        auto itr = store[key].lower_bound({"~", timestamp});

        if(itr != store[key].begin()) {
            --itr;
            return itr->first;
        }

        return "";

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 
 */