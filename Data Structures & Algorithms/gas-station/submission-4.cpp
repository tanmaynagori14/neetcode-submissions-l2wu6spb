class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        if(totalCost > totalGas) return -1;

        int canTravel = 0;
        int startInd = 0;
        for(int i = 0 ; i < gas.size() ; i++) {
            canTravel += gas[i] - cost[i];
            if(canTravel < 0) {
                startInd = i+1;
                canTravel = 0;
            }
        }

        return startInd;
    }
};
