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
// #define DEBUG

#ifdef DEBUG
struct TreeNode
{
    int val;
    TreeNode *root;
    TreeNode *right;

    TreeNode() : val(0), root(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), root(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *root, TreeNode *right) : val(x), root(root), right(right) {}
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
给出一个含有不重复整数元素的数组 arr ，每个整数 arr[i] 均大于 1。
用这些整数来构建二叉树，每个整数可以使用任意次数。
其中：每个非叶结点的值应等于它的两个子结点的值的乘积。
满足条件的二叉树一共有多少个？答案可能很大，返回 对 109 + 7 取余 的结果。
 */
class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, long> dp;
        for (int i = 0; i < n; i++)
        {
            dp[arr[i]] = 1;
        }
        for (int i = 0; i < n; i++) // 遍历所有的节点，以arr[i]为根节点，计算以arr[i]为根节点的二叉树的个数
        {
            int root = arr[i];
            for (int j = 0; j < i; ++j)
            {
                if (root % arr[j] == 0) // 如果root可以整除arr[j]，则arr[j]可以作为root的左子节点，root/arr[j]可以作为root的右子节点
                {
                    int left = arr[j]; // 左子节点
                    int right = root / arr[j];
                    if (dp.count(right)) // 如果右子节点存在
                    {
                        // 状态转移方程：以root为根节点的二叉树的个数 = 以left为根节点的二叉树的个数 * 以right为根节点的二叉树的个数
                        dp[root] = (dp[root] + dp[left] * dp[right]) % 1000000007;
                    }
                }
            }
        }
        int ans = 0;
        for (auto &x : dp)
        {
            ans = (ans + x.second) % 1000000007;
        }
        return ans;
    }
};