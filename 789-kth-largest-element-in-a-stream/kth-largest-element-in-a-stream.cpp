class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    void init(vector<int> &nums) {
        int cnt = k;
        sort(nums.begin(), nums.end());
        int index = nums.size() - 1;

        if(index < 0) return;
        while(cnt && index >= 0) {
            pq.push(nums[index]);
            index--;
            cnt--;
        }
    }
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        init(nums);
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */