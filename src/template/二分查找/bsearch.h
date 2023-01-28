//
// Created by w1z4Rd on 2022/10/30.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 查找第一个值等于给定值的元素
     * @param  nums 排序数组
     * @param  target 目标值
     */
    int bSearch1(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] != target) return mid;
                r = mid - 1; // 说明虽然找到了，但是不是第一个，继续往左找
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
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
    int bSearch2(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + (r - l)) >> 1;
            if (nums[mid] == target) {
                if (mid == nums.size() - 1 || nums[mid + 1] != target) return mid;
                l = mid + 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }

    /**
     * 查找第一个大于等于给定值的元素
     */
    int bSearch3(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + (r - l)) >> 1;
            if (nums[mid] >= target) {
                if (mid == 0 || nums[mid - 1] < target) {
                    return mid;
                } else {
                    r = mid - 1;
                }
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }

    /**
     * 查找最后一个小于等于给定值的元素
     */
    int bSearch4(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + (r - l)) >> 1;
            if (nums[mid] <= target) {
                if (mid == nums.size() - 1 || nums[mid + 1] > target) {
                    return mid;
                } else {
                    l = mid + 1;
                }
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};


