/*
 * @lc app=leetcode.cn id=1513 lang=cpp
 *
 * [1513] 仅含 1 的子串数
 */

// @lc code=start
class Solution
{
public:
    int numSub(string s)
    {
        int len = s.length();
        int ans = 0;
        int cnt = 0; // 记录连续1的个数
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '1')
            {
                cnt++;
                ans = (ans + cnt) % 1000000007;
            }else{
                cnt = 0;
            }
        }
        return ans;
    }
};
// @lc code=end
