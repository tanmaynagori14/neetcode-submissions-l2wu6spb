class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        if(totalGas < totalCost) return -1;
        int n = gas.size();

        int ans = 0, prevgas = 0;
        for(int i=0 ; i<n ; i++) {
            int g = gas[i], c = cost[i];
            prevgas += (g- c);
            if(prevgas < 0) {
                ans = (i+1)%n;
                prevgas = 0;
            };
        }

        return ans;
    }
};
