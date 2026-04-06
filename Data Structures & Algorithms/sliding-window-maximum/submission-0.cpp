class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; // store index
        for(int i=0 ; i<nums.size() ; i++) {
            if(i<k-1) {
                if(dq.empty()) dq.push_front(i);
                else {
                    while(!dq.empty() && nums[dq.front()] <= nums[i]) dq.pop_front();
                    dq.push_front(i);
                }
            } else {
                if(!dq.empty() && dq.back() <= i-k) dq.pop_back();
                while(!dq.empty() && nums[dq.front()] <= nums[i]) dq.pop_front();
                dq.push_front(i);
                ans.push_back(nums[dq.back()]);
            }
        }


        return ans;
    }
};
