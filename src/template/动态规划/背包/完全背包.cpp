using namespace std;

#include <bits/stdc++.h>

class Solution
{
public:
    /**
     * 完全背包问题
     * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
     * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
     * 你可以认为每种硬币的数量是无限的。
     *
     * 01背包：dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
     * 完全背包：dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i]);
     * 01背包和完全背包的区别在于，01背包每个物品只能选一次，完全背包每个物品可以选无数次
     *
     * @param amount  背包容量（总金额）
     * @param coins  物品（硬币）数组
     * @return
     */
    int CompletePack(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int dp[n + 1][amount + 1];
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1])
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            }
        }
        int ans = dp[n][amount];
        if (ans == 0x3f3f3f3f)
            return -1;
        return ans;
    }
};