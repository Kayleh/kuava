class Solution {
    public long countGood(int[] nums, int k) {
        /**
         * 1. 用一个数组记录每个数出现的次数
         */
        int[] count = new int[100001];
        for (int num : nums) {
            count[num]++;
        }
        /**
         * 2. 用一个数组记录每个数的前缀和
         */

    }
}