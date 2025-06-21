class LRUCache {
private:
    list<int> dll;
    unordered_map<int, pair<list<int> :: iterator, int > > mp;
    int n;

    void markRecentlyUsed(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

public:
    LRUCache(int capacity) {
        this->n = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        int val = mp[key].second;
        markRecentlyUsed(key);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            markRecentlyUsed(key);
            return;
        } else {
            dll.push_front(key);
            mp[key] = {dll.begin(),value};
            n--;
        }

        if(n<0){
            mp.erase(dll.back());
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */