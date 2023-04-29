//
// Created by w1z4Rd on 2022/10/30.
//
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    /*二分答案
     珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 h 小时后回来。
    珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。
    珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
    返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。
     */
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // 思路：二分查找，假设以mid的速度吃香蕉，能在h小时内吃完，那么就可以尝试更小的速度，否则尝试更大的速度，直到找到最小的速度

        sort(piles.begin(), piles.end()); // 排序

        /**
         * 检查以speed的速度吃香蕉，是否能在h小时内吃完
         */
        auto check = [&](int speed)
        {
            int time = 0;
            for (int pile : piles) // 遍历每个香蕉堆
            {
                // 以speed的速度吃香蕉，需要的时间
                time += pile / speed + (pile % speed > 0);
            }
            return time <= h;
        };

        // 二分区间
        // 最小值为1(每个小时都要吃，速度肯定是大于等于1的)
        // 最大值为最大的那个香蕉堆(每小时最多吃一个堆，来自题意 “每个小时，她将会选择一堆香蕉，从中吃掉 k 根。” )
        int l = 1, r = piles.back();
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid)) // 如果以mid的速度吃香蕉，能在h小时内吃完，那么就可以尝试更小的速度
                r = mid;
            else
                l = mid + 1;
        }
        return l; // l == r
    }

    /**
     * 查找第一个值等于给定值的元素
     * @param  nums 排序数组
     * @param  target 目标值
     */
    int bSearch1(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                if (mid == 0 || nums[mid - 1] != target)
                    return mid;
                r = mid - 1; // 说明虽然找到了，但是不是第一个，继续往左找
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }

    /**
     * 查找最后一个值等于给定值的元素
     * @param  nums 排序数组
     * @param  target 目标值
     */
    int bSearch2(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + (r - l)) >> 1;
            if (nums[mid] == target)
            {
                if (mid == nums.size() - 1 || nums[mid + 1] != target)
                    return mid;
                l = mid + 1;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }

    /**
     * 查找第一个大于等于给定值的元素
     */
    int bSearch3(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + (r - l)) >> 1;
            if (nums[mid] >= target)
            {
                if (mid == 0 || nums[mid - 1] < target)
                {
                    return mid;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }

    /**
     * 查找最后一个小于等于给定值的元素
     */
    int bSearch4(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + (r - l)) >> 1;
            if (nums[mid] <= target)
            {
                if (mid == nums.size() - 1 || nums[mid + 1] > target)
                {
                    return mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }
};
