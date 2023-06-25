using i64 = long long;
#include <bits/stdc++.h>

/**
 * 一维前缀和
 */
std::vector<int> preSum1d(std::vector<int> &nums)
{
    int n = nums.size();
    std::vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + nums[i];
    }
    return sum;
}

/**
 * 二维前缀和
 */
std::vector<std::vector<int>> preSum2d(std::vector<std::vector<int>> &nums)
{
    int n = nums.size();
    int m = nums[0].size();
    std::vector<std::vector<int>> sum(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + nums[i][j];
        }
    }
    return sum;
}

int get1dSum(std::vector<int> nums, int l, int r)
{
    std::vector<int> sum = preSum1d(nums); // 第
    return sum[r + 1] - sum[l];
}

int get2dSum(std::vector<std::vector<int>> nums, int x1, int y1, int x2, int y2)
{
    std::vector<std::vector<int>> sum = preSum2d(nums);
    return sum[x2 + 1][y2 + 1] - sum[x1][y2 + 1] - sum[x2 + 1][y1] + sum[x1][y1];
}