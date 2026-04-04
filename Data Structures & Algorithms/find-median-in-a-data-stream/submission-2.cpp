class MedianFinder {
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxpq.push(num);

        minpq.push(maxpq.top());
        maxpq.pop();

        if(minpq.size() > maxpq.size()) {
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        if(maxpq.size() > minpq.size()) return maxpq.top();
        return (minpq.top() + maxpq.top()) / 2.0;
    }
};
