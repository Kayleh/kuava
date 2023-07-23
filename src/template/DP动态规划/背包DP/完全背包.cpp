using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    /**
     * 完全背包问题
     * 给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。
     *
     * @param amount  背包容量（总金额）
     * @param coins  物品（硬币）数组
     * @return
     */
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        int dp[n + 1][amount + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - coins[i - 1] >= 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[n][amount];
    }

    /* 一维数组优化，注意内层循环的遍历顺序 */
    int change2(int amount, vector<int> &coins) {
        int n = coins.size();
        int dp[amount + 1]; // dp[i] 表示凑成总金额为i的硬币组合数
        memset(dp, 0, sizeof(dp));
        dp[0] = 1; // 凑成总金额为0的硬币组合数为1
        for (int i = 0; i < n; i++) { // 枚举硬币
            for (int j = coins[i]; j <= amount; j++) { // 枚举金额
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};