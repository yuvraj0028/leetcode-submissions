class MyHashMap {
public:
    int n = 10000;
    vector<vector<pair<int,int> > > v;
    MyHashMap() {
        v.resize(n);
    }
    
    void put(int key, int value) {
        int index = key%n;

        for(auto &[k,v] : v[index]){
            if(k == key){
                v = value;
                return;
            }
        }

        v[index].push_back({key,value});
    }
    
    int get(int key) {
        int index = key % n;

        for(auto &[k,v] : v[index]){
            if(k == key){
                return v;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int index = key%n;

        for(int i = 0; i<v[index].size();i++){
            if(v[index][i].first == key){
                v[index].erase(v[index].begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */