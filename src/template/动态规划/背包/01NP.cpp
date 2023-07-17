using namespace std;

#include <bits/stdc++.h>


/**
 * 01背包问题
 * 给你一个可装载重量为W的背包和N个物品，每个物品有重量和价值两个属性。 其中第i个物品的重量为w[i]，价值为v[i]，现在让你用这个背包装物品，最多能装的价值是多少？
 * @return
 */
int knapsack01(vector<int> &w, vector<int> &v, int W) {
    int n = w.size();
    // dp[i][j]表示仅考虑前i个物品，总重量不超过j的情况下，最大的总价值
    vector <vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            int cur = j - w[i - 1]; // 如果当前背包容量j大于等于第i个物品的重量w[i-1]，则可以选择装入或者不装入背包
            if (j - w[i - 1] < 0) {
                // 背包容量不足，不能装入第i个物品
                dp[i][j] = dp[i - 1][j];
            } else {
                // 装入或者不装入背包
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }
    return dp[n][W];
}


int main() {

}