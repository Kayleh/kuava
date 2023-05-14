/*
    $ codeforce

    Copyright 2022  Kayleh. All rights reserved.
    @see {@link https://github.com/Kayleh/kuava}

           ,-.                              ,--,                 ,---,
       ,--/ /|                            ,--.'|               ,--.' |
     ,--. :/ |                            |  | :               |  |  :
     :  : ' /                             :  : '               :  :  :
     |  '  /       ,--.--.          .--,  |  ' |       ,---.   :  |  |,--.
     '  |  :      /       \       /_ ./|  '  | |      /     \  |  :  '   |
     |  |   \    .--.  .-. |   , ' , ' :  |  | :     /    /  | |  |   /' :
     '  : |. \    \__\/: . .  /___/ \: |  '  : |__  .    ' / | '  :  | | |
     |  | ' \ \   ," .--.; |   .  \  ' |  |  | '.'| '   ;   /| |  |  ' | :
     '  : |--'   /  /  ,.  |    \  ;   :  ;  :    ; '   |  / | |  :  :_:,'
     ;  |,'     ;  :   .'   \    \  \  ;  |  ,   /  |   :    | |  | ,'
     '--'       |  ,     .-./     :  \  \  ---`-'    \   \  /  `--''
                 `--`---'          \  ' ;             `----'
                                    `--`
@Date: 2020/6/14 19:34
*/

// #include "Solution.h"
#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>
// #include <cassert>
#include <unordered_set>

#ifdef kOS
#define INPUT_FILE "C:/input.txt"
#define OUTPUT_FILE "C:/output.txt"
#endif

#define PI 3.14159265358979323846
#define gcd(a, b) __gcd(a, b)             // 最大公约数
#define bitcount(a) __builtin_popcount(a) // 二进制中1的个数
#define lcm(a, b) (a * b / gcd(a, b))     // 最小公倍数
// #define max(a, b) (a > b ? a : b)                         // 最大值
#define swapp(a, b) (a ^= b; b ^= a; a ^= b)              // 交换
#define forin(item, arr) for (auto item : arr)            // 遍历
#define rep(i, from, to) for (int i = from; i <= to; i++) // 递增
#define per(i, from, to) for (int i = from; i >= to; i--) // 递减
#define ll long long
#define ull unsigned long long
#define changeCase(c) (c ^ (1 << 5))           // 大小写互换
#define isLetter(c) (isalpha(c))               // 判断是否为字母
#define INF 0x3f3f3f3f                         // 无穷大
#define NINF 0xc0c0c0c0                        // 无穷小
#define randd(a, b) (rand() % (b - a + 1) + a) // [a, b]

template <typename T>
bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }

template <typename T>
bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
{ return a.second < b.second; };

// #define debug

#ifdef debug
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

using namespace std;

//@start——————————————————————————————————————————————————————————————————————

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        // 有两种情况
        // 1. 最大子数组和不跨越数组首尾，那么就是普通的动态规划求最大子数组和
        // 2. 最大子数组和跨越数组首尾，一部分在数组首，一部分在数组尾。 由于在不同的位置，所以求最大子数组和不方便，但是可以求最小子数组和
        // 此时，最小子数组和一定在中间，所以最大子数组和 = 总和 - 最小子数组和

        // 环形数组的最大子数组和 = max(总和 - 最小子数组和, 最大子数组和)
        int n = nums.size();
        int maxSum = nums[0], minSum = nums[0]; // 最大值和最小值
        int curMax = 0, curMin = 0;             // 当前最大值和最小值
        int total = 0;                          // 总和
        for (int i = 0; i < n; i++)
        {
            curMax = max(curMax + nums[i], nums[i]); // 当前最大值
            maxSum = max(maxSum, curMax);            // 最大值
            curMin = min(curMin + nums[i], nums[i]); // 当前最小值
            minSum = min(minSum, curMin);            // 最小值
            total += nums[i];                        // 总和
        }

        // 如果最大的子数组和小于0，说明数组中的元素都是负数，那么最大子数组和就是最大的元素
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};