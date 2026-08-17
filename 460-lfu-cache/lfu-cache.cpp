class LFUCache {
private:
    struct Node{
        int key;
        int value;
        int freq;
    };

    int maxCapacity;
    int minFreq;

    // key -> node address
    unordered_map<int, list<Node>::iterator> keyToAddress;
    
    // freq -> actual nodes list
    unordered_map<int, list<Node>> freqMap;
public:
    LFUCache(int capacity) {
        maxCapacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyToAddress.find(key) == keyToAddress.end()) {
            return -1;
        }

        auto nodeItr = keyToAddress[key];
        int val = nodeItr->value;
        int freq = nodeItr->freq;

        freqMap[freq].erase(nodeItr);
        if(freqMap[freq].empty()) {
            freqMap.erase(freq);

            if(minFreq == freq) minFreq++;
        }

        freqMap[freq+1].push_front({key,val,freq+1});
        keyToAddress[key] = freqMap[freq+1].begin();

        return val;
    }
    
    void put(int key, int value) {
        if(maxCapacity == 0) return;

        if(keyToAddress.find(key) != keyToAddress.end()) {
            keyToAddress[key]->value = value;
            get(key);
            return;
        }

        if(keyToAddress.size() == maxCapacity) {
            int keyToRemove = freqMap[minFreq].back().key;
            keyToAddress.erase(keyToRemove);
            freqMap[minFreq].pop_back();

            if(freqMap[minFreq].empty()) {
                freqMap.erase(minFreq);
            }
        }

        freqMap[1].push_front({key,value,1});
        keyToAddress[key] = freqMap[1].begin();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */