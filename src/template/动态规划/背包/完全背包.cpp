using namespace std;

#include <bits/stdc++.h>

class Solution
{
public:
    /**
     * 完全背包问题
     * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
     * 求出并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0
     * @param amount  背包容量（总金额）
     * @param coins  物品（硬币）数组
     * @return
     */
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        // dp[i] 表示组成金额 i 的方案数
        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // 金额为0时，方案数为1（什么都不选）

        for (int i = 0; i < n; i++) // 遍历所有物品。
        {
            for (int j = coins[i]; j <= amount; j++) // 遍历所有容量
            {
                // 组成容量 j 的方案数 = 所有组成容量 j - coins[i] 的方案数之和
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};