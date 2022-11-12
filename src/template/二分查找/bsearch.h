//
// Created by w1z4Rd on 2022/10/30.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>


using namespace std;

class Solution {
public:
    int bSearch1(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + (r - l)) >> 1; // 防止溢出
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};


