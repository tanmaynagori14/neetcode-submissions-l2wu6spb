class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto it: nums) {
            pq.push(it);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() != k) pq.pop();
        return pq.top();
    }
};
