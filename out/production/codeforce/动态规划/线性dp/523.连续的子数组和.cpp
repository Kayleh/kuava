/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
using namespace std;
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n < 2)
            return false;
        unordered_map<int, int> mp; // mp[i] 表示前缀和对 k 取模的结果为 i 的最小下标
        mp[0] = -1;
        int remainder = 0;
        for (int i = 0; i < n; i++)
        {
            remainder = (remainder + nums[i]) % k;
            if (mp.count(remainder))
            {
                int prevIndex = mp[remainder];
                if (i - prevIndex >= 2)
                    return true;
            }
            else
            {
                mp[remainder] = i;
            }
        }
        return false;
    }
};
// @lc code=end
