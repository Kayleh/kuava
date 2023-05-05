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

#define PI 3.14159265358979323846
#define gcd(a, b) __gcd(a, b)             // 最大公约数
#define bitcount(a) __builtin_popcount(a) // 二进制中1的个数
#define lcm(a, b) (a * b / gcd(a, b))     // 最小公倍数
// #define max(a, b) (a > b ? a : b)         // 最大值
// #define min(a, b) (a < b ? a : b)         // 最小值
//  #define abs(a) (a > 0 ? a : -a)                           // 绝对值
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

bool down(int a, int b) { return a > b; } // 降序
bool up(int a, int b) { return a < b; }   // 升序
template <typename T>
bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }

template <typename T>
bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }
/*struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {}ListNode(int x) : val(x), next(nullptr) {}ListNode(int x, ListNode *next) : val(x), (next) {}};*/
/* struct TreeNode{int val;TreeNode *left;  TreeNode *right;    TreeNode() : val(0), left(nullptr), right(nullptr) {}    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}}; */

using namespace std;

int main()
{
    int N;
    cin >> N;
    // 输入一个偶数 N，验证 4∼N 所有偶数是否符合哥德巴赫猜想：任一大于 2 的偶数都可写成两个质数之和。如果一个数不止一种分法，则输出第一个加数相比其他分法最小的方案。
    for (int i = 4; i < N; i++)
    {
        if (i % 2 == 0)
        {
            int a = i / 2; // 从中间开始
            int b = i / 2; // 从中间开始
            while (a > 1)
            {
                if (b % a == 0)
                {
                    a--;
                    b++;
                }
                else
                {
                    cout << i << "=" << a << "+" << b << endl;
                    break;
                }
            }
        }
    }
    return 0;
};