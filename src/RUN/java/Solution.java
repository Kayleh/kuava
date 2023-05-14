/**
 * 给你一个下标从 0 开始长度为 n 的整数数组 nums 和一个整数 k 。每一次操作中，你可以选择一个数并将它乘 2 。
 * <p>
 * 你最多可以进行 k 次操作，请你返回 nums[0] | nums[1] | ... | nums[n - 1] 的最大值。
 * <p>
 * a | b 表示两个整数 a 和 b 的 按位或 运算。
 */
class Solution {
    public long maximumOr(int[] nums, int k) {
        int m = nums.length;
        long yes = (long) (Math.pow(2, k) * nums[0]), no = nums[0];
        for (int i = 1; i < m; i++) {
            // 1. yes | nums[i] 已经包含了 nums[i] 乘 2 的情况下
            // 2. no | (long) (Math.pow(2, k) * nums[i]) 包含了 nums[i] 乘 2 的情况下
            yes = Math.max(yes | nums[i], no | (long) (Math.pow(2, k) * nums[i]));
             no |= nums[i];
        }
        return yes;
    }

    public static void main(String[] args) {
        int[] nums = {12, 9};
        int k = 1;
        Solution solution = new Solution();
        System.out.println(solution.maximumOr(nums, k));
    }
}