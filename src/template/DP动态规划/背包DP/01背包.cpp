using namespace std;

#include <bits/stdc++.h>

/**
 * 01背包问题
 * 给你一个可装载重量为W的背包和N个物品，每个物品有重量和价值两个属性。
 * 其中第i个物品的重量为w[i]，价值为v[i]，现在让你用这个背包装物品，最多能装的价值是多少？
 * @return
 */
int knapsack01(vector<int> &w, vector<int> &v, int W) {
    int n = w.size();
    // dp[i][j]表示仅考虑前i个物品，总重量不超过j的情况下，最大的总价值
    vector <vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    int dp[n + 1][W + 1];
    for (int i = 1; i <= n; i++) // 枚举前i个物品
    {
        for (int j = 1; j <= W; j++) // 枚举背包容量的大小状态
        {
            dp[i][j] = dp[i - 1][j];                                          // 不选第i个物品
            if (j >= w[i - 1])                                                // 背包容量够装第i个物品,尝试装入背包
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + v[i - 1]); // 选第i个物品
        }
    }
    return dp[n][W];
}
