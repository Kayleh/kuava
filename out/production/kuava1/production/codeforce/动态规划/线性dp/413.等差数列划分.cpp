/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        int dp = 0; // dp[i]表示以nums[i]结尾的等差数列的个数
        int res = 0;
        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                dp = 1 + dp;
                // 等差数列的个数，此时子数组的长度至少为3，所以如果当前还是等差数列，那么之前的等差数列的个数也要加上
                res += dp; // 比如[1,2,3,4]，当遍历到4的时候，dp=2，res=2，此时还是等差数列，所以res=2+2=4
            }
            else
                dp = 0;
        }
        return res;
    }
};
// @lc code=end
