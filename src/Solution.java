class Solution {
    public int longestSubarray(int[] nums) {
        //按位与（bitwise AND）运算得到的值 最大 的 非空 子数组。
        //令 k 是 nums 任意 子数组执行按位与运算所能得到的最大值。那么，只需要考虑那些执行一次按位与运算后等于 k 的子数组。

        // 1. 求出 nums 中的最大值 max
        int max = 0;
        for (int num : nums) {
            max = Math.max(max, num);
        }
        // 2. 求出 max 的二进制表示中 1 的个数
        int count = 0;
        while (max > 0) {
            max >>= 1;
            count++;
        }
        // 3. 求出 2^count - 1
        int k = (1 << count) - 1;
        // 4. 求出 nums 中执行一次按位与运算后等于 k 的子数组的最大长度
        int res = 0;
        int left = 0, right = 0;
        int sum = 0;
        while (right < nums.length) {
            sum += nums[right];
            while (sum > k) {
                sum -= nums[left];
                left++;
            }
            res = Math.max(res, right - left + 1);
            right++;
        }


        return res - 1;
    }
}