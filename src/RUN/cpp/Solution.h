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

//#include "Solution.h"
#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>
//#include <cassert>
#include <unordered_set>
#define PI 3.14159265358979323846
#define gcd(a, b) __gcd(a, b)                             // 最大公约数
#define bitcount(a) __builtin_popcount(a)                 // 二进制中1的个数
#define lcm(a, b) (a * b / gcd(a, b))                     // 最小公倍数
#define max(a, b) (a > b ? a : b)                         // 最大值
#define min(a, b) (a < b ? a : b)                         // 最小值
#define abs(a) (a > 0 ? a : -a)                           // 绝对值
#define swapp(a, b) (a ^= b; b ^= a; a ^= b)              // 交换
#define forin(item, arr) for (auto item : arr)            // 遍历
#define rep(i, from, to) for (int i = from; i <= to; i++) // 递增
#define per(i, from, to) for (int i = from; i >= to; i--) // 递减
#define ll long long
#define ull unsigned long long
#define changeCase(c) (c ^ (1 << 5)) // 大小写互换
#define isLetter(c) (isalpha(c))     // 判断是否为字母
#define INF 0x3f3f3f3f               // 无穷大
#define NINF 0xc0c0c0c0              // 无穷小
template <typename T>
bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T>
bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }
/*struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {}ListNode(int x) : val(x), next(nullptr) {}ListNode(int x, ListNode *next) : val(x), (next) {}};*/
/* struct TreeNode{int val;TreeNode *left;  TreeNode *right;    TreeNode() : val(0), left(nullptr), right(nullptr) {}    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}}; */

using namespace std;

//@start——————————————————————————————————————————————————————————————————————

/*
//给你一个长度为 n 的数组 nums ，该数组由从 1 到 n 的 不同 整数组成。另给你一个正整数 k 。
//
//统计并返回 num 中的 中位数 等于 k 的非空子数组的数目。
//
//注意：
//
//数组的中位数是按 递增 顺序排列后位于 中间 的那个元素，如果数组长度为偶数，则中位数是位于中间靠 左 的那个元素。
//例如，[2,3,1,4] 的中位数是 2 ，[8,4,3,5,1] 的中位数是 4 。
//子数组是数组中的一个连续部分。
*/
class Solution
{
public:
    int countSubarrays(vector<int> &nums, int k)
    {
        // 思路：滑动窗口 + 前缀和

        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + nums[i - 1];
        }

        int ans = 0;
        int l = 0, r = 0; // 滑动窗口的左右边界
        while (r < n)
        {
            if (pre[r + 1] - pre[l] == k / (r - l + 1))
            {
                ans++;
                r++;
            }
            else if (pre[r + 1] - pre[l] < k / (r - l + 1))
            {
                r++;
            }
            else
            {
                l++;
            }
        }

        return ans;
    }
};