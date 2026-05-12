class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> indexes;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(indexes.find(val) != indexes.end()) return false;
        nums.push_back(val);
        indexes[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(indexes.find(val) == indexes.end()) return false;

        int valIndex = indexes[val];
        int lastElem = nums[nums.size() - 1];

        nums[valIndex] = lastElem;
        nums.pop_back();

        indexes[lastElem] = valIndex;
        indexes.erase(val);

        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */