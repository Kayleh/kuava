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
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>
//#include <cassert>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string.h>

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
//#define isPrime(n) (n == 2 || (n > 2 && (n & 1) && !isComposite(n))) // 判断是否为素数（质数）
//#define isComposite(n) (n > 2 && (n & 1) && !isPrime(n))            // 判断是否为合数(非质数)

/*struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {}ListNode(int x) : val(x), next(nullptr) {}ListNode(int x, ListNode *next) : val(x), (next) {}};*/
/* struct TreeNode{int val;TreeNode *left;  TreeNode *right;    TreeNode() : val(0), left(nullptr), right(nullptr) {}    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}}; */

using namespace std;

//@start——————————————————————————————————————————————————————————————————————

class Solution
{
public:
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> preSum(n + 1);
        for (int i = 1; i <= n; i++)
        {
            preSum[i] = preSum[i - 1] + stones[i - 1]; // 前缀和
        }

        vector<vector<int>> dp(n, vector<int>(n)); // dp[i][j] 表示当剩下的石子堆为下标 i 到下标 j 时，当前玩家与另一个玩家的石子数量之差的最大值，注意当前玩家不一定是先手。
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = max(preSum[j + 1] - preSum[i + 1] - dp[i + 1][j], preSum[j] - preSum[i] - dp[i][j - 1]); // 当前玩家选择最左边的石子堆或最右边的石子堆。
            }
        }
        return dp[0][n - 1];
    }
};