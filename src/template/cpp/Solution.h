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

/**
 * 给你整数 zero ，one ，low 和 high ，我们从空字符串开始构造一个字符串，每一步执行下面操作中的一种：

将 '0' 在字符串末尾添加 zero  次。
将 '1' 在字符串末尾添加 one 次。
以上操作可以执行任意次。

如果通过以上过程得到一个 长度 在 low 和 high 之间（包含上下边界）的字符串，那么这个字符串我们称为 好 字符串。
请你返回满足以上要求的 不同 好字符串数目。由于答案可能很大，请将结果对 109 + 7 取余 后返回。
*/
class Solution
{
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        int mod = 1e9 + 7;
        // dp[i][j][k] 表示长度为i，0的个数为j，1的个数为k的字符串的个数
        vector<vector<vector<int>>> dp(high + 1, vector<vector<int>>(zero + 1, vector<int>(one + 1, 0)));
        dp[0][0][0] = 0; // 空字符串

        for (int i = 1; i <= high; i++) // 长度
        {
            for (int j = zero; j >= 0; j--) // 0的个数
            {
                for (int k = one; k >= 0; k--) // 1的个数
                {
                    if (j == 0 && k == 0) // 0和1都没有 无法构造
                        continue;
                    if (j == 0)
                    {
                        // 只能构造1 , 1的个数减1, 长度加1
                        dp[i][j][k] = dp[i + 1][j][k - 1];
                    }
                    else if (k == 0)
                    {
                        // 只能构造0 , 0的个数减1, 长度加1
                        dp[i][j][k] = dp[i + 1][j - 1][k];
                    }
                    else
                    {
                        // 0和1都可以构造, 0的个数减1, 长度加1 和 1的个数减1, 长度加1
                        dp[i][j][k]  = (dp[i + 1][j - 1][k] + dp[i + 1][j][k - 1]) % mod;
                    }
                }
            }
        }

       /*  for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[i].size(); j++)
            {
                for (int k = 0; k < dp[i][j].size(); k++)
                {
                    cout << dp[i][j][k] << " ";
                }
                cout << endl;
            }
            cout << endl;
        } */

    // 计算low到high的字符串个数
        int ans = 0;
        for (int i = low; i <= high; i++)
        {
            for (int j = 0; j <= zero; j++)
            {
                for (int k = 0; k <= one; k++)
                {
                    ans += dp[i][j][k];
                    ans %= mod;
                }
            }
        } 
        return ans;
    }
};