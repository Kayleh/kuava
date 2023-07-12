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

template<class T>
inline void ckmin(T &a, T b) { a = min(a, b); }

template<class T>
inline void ckmax(T &a, T b) { a = max(a, b); }

template<class T>
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

class Solution {
public:
    long long maxAlternatingSum(vector<int> &nums) {
        int n = nums.size();
        ll NINF2 = NINF / 2;
        vector<vector<ll>> dp(n + 1, vector<ll>(2, NINF2));// dp[i][0]前i个数，奇数序列的最大值，dp[i][1]前i个数，偶数序列的最大值
        dp[0][0] = 0;
        dp[0][1] = 0;
        for (int i = 1; i <= n; i++) {
            // 1。不选nums[i-1]，则dp[i][0] = dp[i-1][0]
            // 2。选nums[i-1]，则dp[i][0] = dp[i-1][1] + nums[i-1]
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - nums[i - 1]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};