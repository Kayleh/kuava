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
// #define debug

//@start——————————————————————————————————————————————————————————————————————

class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        // 并查集
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i; // 初始化
        for (auto dislike : dislikes)
        {
            int x = dislike[0], y = dislike[1];
            if (find(parent, x) == find(parent, y)) 
                return false;
            unionSet(parent, x, y); 
        }
        return true;
    }

    int find(vector<int> &parent, int index)
    {
        if (parent[index] != index)
            parent[index] = find(parent, parent[index]);
        return parent[index];
    }

    void unionSet(vector<int> &parent, int index1, int index2)
    {
        parent[find(parent, index1)] = find(parent, index2);
    }
};
