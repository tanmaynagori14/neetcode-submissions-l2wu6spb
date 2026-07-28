class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] arr = new int[n-k+1];

        ArrayDeque<Integer> dq = new ArrayDeque<>();
        for(int i = 0 ; i < n ; i++) {
            if(i < k-1) {
                while(!dq.isEmpty() && nums[dq.peekLast()] <= nums[i]) dq.pollLast();
                dq.offerLast(i);
            } else {
                // i == k
                while(!dq.isEmpty() && nums[dq.peekLast()] <= nums[i]) dq.pollLast();
                while(!dq.isEmpty() && dq.peekFirst() <= i-k) dq.pollFirst();
                dq.offerLast(i);
                arr[i-k+1] = nums[dq.peekFirst()];
            }
        }
        return arr;
    }
}
