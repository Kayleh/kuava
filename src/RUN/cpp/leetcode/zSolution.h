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

#include <bits/stdc++.h>

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
#define POW(a, b) (int)pow(a, b)
#define toBinary(x) bitset<8 * sizeof(x)>((x)).to_string()

#define fio                            \
    ios::base::sync_with_stdio(false); \
    cin.tie(NULL);

template <class T>
inline void ckmin(T &a, T b) { a = min(a, b); }

template <class T>
inline void ckmax(T &a, T b) { a = max(a, b); }

template <class T>
void COPY(T a[], const T b[], int n) { memcpy(a, b, n * sizeof(T)); }

/* template <class T>
inline void MEMSET(T a, int b) { memset(a, b, sizeof(a)); } */

// auto cmpp = [](const pair<int, int> &a, const pair<int, int> &b)
//{ return a.second < b.second; };

#ifdef DEBUG

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

#endif

using namespace std;

#include <bits/stdc++.h>

/**
给你一个下标从 0 开始的整数数组 nums ，表示一些石块的初始位置。再给你两个长度 相等 下标从 0 开始的整数数组 moveFrom 和 moveTo 。

在 moveFrom.length 次操作内，你可以改变石块的位置。在第 i 次操作中，你将位置在 moveFrom[i] 的所有石块移到位置 moveTo[i] 。

完成这些操作后，请你按升序返回所有 有 石块的位置。

注意：

如果一个位置至少有一个石块，我们称这个位置 有 石块。
一个位置可能会有多个石块。
*/

struct Node
{
    int to, next;
} edge[100005];

int head[100005], cnt;

void add(int u, int v)
{
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void init(int n)
{
    cnt = 0;
    for (int i = 0; i <= n; i++)
        head[i] = -1;
}

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        int *vis = new int[1005]; // vis[i] = 1 表示出现了i次的数有多个
        int *cnt = new int[2005]; // cnt[i] = j 表示i出现了j次
        memset(cnt, 0, sizeof(cnt));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < arr.size(); i++)
        {
            cnt[arr[i] + 1000]++;
        }

        /* for (int i = 0; i < 2005; i++)
        {
            if (cnt[i] != 0)
            {
                if (vis[cnt[i]] == 1)
                    return false;
                vis[cnt[i]] = 1;
            }
        } */
        return true;
    }
};
;
