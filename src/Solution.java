class Solution {
    public int subarrayGCD(int[] nums, int k) {
        //统计并返回 nums 的子数组中元素的最大公因数等于 k 的子数组数目。

        //数组的最大公因数 是能整除数组中所有元素的最大整数。
        // 例如，数组 [4,6,16] 的最大公因数是 2 。


        int n = nums.length;


        int[] dp = new int[n];
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = gcd(dp[i - 1], nums[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] % k == 0) {
                ans++;
            }
        }

        
        return ans;
    }

    /**
     * 求最大公因数
     *
     * @param num
     * @param k
     * @return
     */
    private int gcd(int num, int k) {
        if (num == 0) return k;
        return gcd(k % num, num);
    }

    public static void main(String[] args) {
        int[] nums = {9, 3, 1, 2, 6, 3};
        int k = 3;
        Solution solution = new Solution();
        int ans = solution.subarrayGCD(nums, k);
        System.out.println(ans);

        nums = new int[]{5};
        k = 1;
        ans = solution.subarrayGCD(nums, k);
        System.out.println(ans);


        //数组的最大公因数 是能整除数组中所有元素的最大整数。
        nums = new int[]{7, 5, 6, 8, 3};
        k = 5;

    }
}