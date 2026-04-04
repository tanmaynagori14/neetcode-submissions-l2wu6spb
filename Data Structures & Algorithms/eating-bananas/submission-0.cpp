class Solution {
public:
    // helper function
    bool isPossible(int speed, vector<int>& piles, int h) {
        long long totalHours = 0;

        for(int pile : piles) {
            // ceil(pile / speed)
            totalHours += (pile + speed - 1) / speed;
        }

        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for(auto it : piles) maxi = max(maxi, it);

        int s = 1, e = maxi;
        int ans = maxi;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(isPossible(mid, piles, h)) {
                ans = mid;
                e = mid - 1;  // try smaller speed
            } else {
                s = mid + 1;  // need more speed
            }
        }

        return ans;
    }
};
