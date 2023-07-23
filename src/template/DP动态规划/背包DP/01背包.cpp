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


/**
 * 给你一个整数数组 nums 和一个整数 target 。
 * 向数组中的每个整数前添加 ‘+’ 或 ‘-‘ ，然后串联起所有整数，可以构造一个 表达式 ：
 * 例如，nums = [2, 1] ，可以在 2 之前添加 ‘+’ ，在 1 之前添加 ‘-‘ ，然后串联起来得到表达式 “+2-1” 。
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 */
int findTargetSumWays(vector<int> nums, int t) {
    int n = nums.size();
    int s = 0;
    for (int i = 0; i < n; i++) s += nums[i];
    if (s < t || (s - t) % 2) return 0;
    int bagSize = (s - t) / 2;
    int dp[n + 1][bagSize + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int x = nums[i - 1];
        for (int j = 0; j <= bagSize; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= x) dp[i][j] += dp[i - 1][j - x];
        }
    }
    return dp[n][bagSize];
}
