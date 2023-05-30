using i64 = long long;
#include <bits/stdc++.h>

/**
 * 一维前缀和
*/
void preSum1(std::vector<int> &nums)
{
    int n = nums.size();
    std::vector<int> sum(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            sum[i] = nums[i];
        else
            sum[i] = nums[i] + sum[i - 1];
    }
}

/**
 * 二维前缀和
*/
void preSum2(std::vector<std::vector<int>> &nums)
{
    int n = nums.size();
    int m = nums[0].size();
    std::vector<std::vector<int>> sum(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; i++)
        {
            if (i == 0 && j == 0)
                sum[i][j] = nums[i][j];
            else if (i == 0)
                sum[i][j] = nums[i][j] + sum[i][j - 1];
            else if (j == 0)
                sum[i][j] = nums[i][j] + sum[i - 1][j];
            else
                sum[i][j] = nums[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
}