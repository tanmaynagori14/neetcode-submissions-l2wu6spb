class Solution {
    int bis(int num, vector<int> &temp) {
        int s = 0, e = temp.size()-1;
        while(s <= e) {
            int mid = (s + e) / 2;
            if(temp[mid] < num) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return s;

    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        for(auto it: nums) {
            if(temp.size() == 0) {temp.push_back(it); continue;}
            int idx = bis(it, temp);
            if(idx == temp.size()) temp.push_back(it);
            else temp[idx] = it;
        }

        return temp.size();
    }
};
