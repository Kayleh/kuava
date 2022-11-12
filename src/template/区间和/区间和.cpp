
#include <bits/stdc++.h>
using namespace std;

/**
 * 区间和 - 模板
 */
class NumArray
{
public:
    vector<int> &nums;
    NumArray(vector<int> &nums)
    {
        this->nums = nums;
    };

    /**
     *  区间和数组
     * @param nums 原数组
     * @return 区间和数组, sum[i][j] 表示 nums[i] 到 nums[j] 的区间和
     */
    vector<vector<int>> getRangeSumList()
    {
        int n = nums.size();
        vector<vector<int>> sum(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j)
                    sum[i][j] = nums[i]; //记录区间和
                else
                    sum[i][j] = nums[j] + sum[i][j - 1];
            }
        }
        return sum;
    }

    /**
     * 前缀和数组
     */
    vector<int> getPrefixSumList()
    {
        int n = nums.size();
        vector<int> sum(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                sum[i] = nums[i];
            else
                sum[i] = nums[i] + sum[i - 1];
        }
        return sum;
    }

    /**
     *  差分数组
     * @param nums 原数组
     * @return 差分数组, diff[i] 表示 nums[i] 到 nums[i+1] 的差值
     */
    vector<int> getDiffList()
    {
        int n = nums.size();
        vector<int> diff(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                diff[i] = nums[i];
            else
                diff[i] = nums[i] - nums[i - 1];
        }
        return diff;
    }

    /**
     *  差分数组转原数组
     * @param diff 差分数组
     * @return 原数组
     */
    vector<int> diffListToNums(vector<int> &diff)
    {
        int n = diff.size();
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                nums[i] = diff[i];
            else
                nums[i] = nums[i - 1] + diff[i];
        }
        return nums;
    }
};