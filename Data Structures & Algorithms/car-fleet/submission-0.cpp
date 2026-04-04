class Solution {
public:
    
    // Custom comparator: sort based on position in descending order
    static bool comp(pair<int, double> &a, pair<int, double> &b) {
        return a.first > b.first;
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        
        vector<pair<int, double>> cars;
        
        // Step 1: store position + time
        for(int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        
        // Step 2: sort using comparator
        sort(cars.begin(), cars.end(), comp);
        
        // Step 3: count fleets
        int fleets = 0;
        double prevTime = 0;
        
        for(int i = 0; i < n; i++) {
            double currTime = cars[i].second;
            
            if(currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            }
        }
        
        return fleets;
    }
};
