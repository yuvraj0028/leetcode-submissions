class LRUCache {
private:
    unordered_map<int, pair<list<int>::iterator, int > > keyToNodeAddress;
    list<int> nodes;
    int size;

    void markRecentlyUsed(int key) {
        // nodes.erase(keyToNodeAddress[key].first);
        // nodes.push_front(key);
        // keyToNodeAddress[key].first = nodes.begin();

        nodes.splice(nodes.begin(), nodes, keyToNodeAddress[key].first);
    }

public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto itr = keyToNodeAddress.find(key);
        if(itr == keyToNodeAddress.end()) {
            return -1;
        }

        int val = itr->second.second;
        markRecentlyUsed(key);
        return val;
    }
    
    void put(int key, int value) {
        auto itr = keyToNodeAddress.find(key);
        if(itr != keyToNodeAddress.end()) {
            itr->second.second = value;
            markRecentlyUsed(key);
            return;
        }

        nodes.push_front(key);
        keyToNodeAddress[key] = {nodes.begin(), value};
        size--;

        if(size<0) {
            keyToNodeAddress.erase(nodes.back());
            nodes.pop_back();
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */