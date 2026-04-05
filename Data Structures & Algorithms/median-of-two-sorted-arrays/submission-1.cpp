class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        
        int elesOnLeft = (n1 + n2 + 1) / 2;
        int low = 0, high = n1;
        int l1, l2, r1, r2;

        while(low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = elesOnLeft - mid1;

            l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];

            l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

            if(l1 > r2) high = mid1-1;
            else if(l2 > r1) low = mid1+1;
            else break;
        }

        if((n1 + n2) % 2 == 1) return max(l1, l2);
        return ((max(l1, l2) + min(r1, r2)) / 2.0);
    }
};
