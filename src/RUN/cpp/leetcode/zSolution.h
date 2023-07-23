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
// #define DEBUG

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
[2,3,6,1,9,2]
5
[2,4,6,8]
3
[38,92,23,30,25,96,6,71,78,77,33,23,71,48,87,77,53,28,6,20,90,83,42,21,64,95,84,29,22,21,33,36,53,51,85,25,80,56,71,69,5,21,4,84,28,16,65,7]
52
[9,58,17,54,91,90,32,6,13,67,24,80,8,56,29,66,85,38,45,13,20,73,16,98,28,56,23,2,47,85,11,97,72,2,28,52,33]
90
 */

/**
给你一个下标从 0 开始的整数数组 nums 和一个正整数 x 。
你 一开始 在数组的位置 0 处，你可以按照下述规则访问数组中的其他位置：
1.如果你当前在位置 i ，那么你可以移动到满足 i < j 的 任意 位置 j 。
2.对于你访问的位置 i ，你可以获得分数 nums[i] 。
3.如果你从位置 i 移动到位置 j 且 nums[i] 和 nums[j] 的 奇偶性 不同，那么你将失去分数 x 。
请你返回你能得到的 最大 得分之和。

注意 ，你一开始的分数为 nums[0] 。
 */
class Solution {
public:
    long long maxScore(vector<int> &nums, int x) {
        int n = nums.size();
        long long dp[n][2]; // dp[i][0] 表示到第i个位置，且最后一个数是偶数的最大得分, dp[i][1] 表示到第i个位置，且最后一个数是奇数的最大得分
        memset(dp, 0, sizeof(dp));
        dp[0][nums[0] % 2] = nums[0];
        dp[0][nums[0] % 2 ^ 1] = nums[0];
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0 ; --j) {
                if (nums[i] % 2 == nums[j] % 2) {
                    dp[i][nums[i] % 2] = max(dp[i][nums[i] % 2], dp[j][nums[j] % 2] + nums[i]);
                    dp[i][nums[i] % 2 ^ 1] = max(dp[i][nums[i] % 2 ^ 1], dp[j][nums[j] % 2 ^ 1] + nums[i]);
                } else {
                    dp[i][nums[i] % 2] = max(dp[i][nums[i] % 2], dp[j][nums[j] % 2] + nums[i] - x);
                    dp[i][nums[i] % 2 ^ 1] = max(dp[i][nums[i] % 2 ^ 1], dp[j][nums[j] % 2 ^ 1] + nums[i] - x);
                }
            }
        }

        // print dp
        for (int i = 0; i < n; i++) {
            cout << dp[i][0] << " " << dp[i][1] << endl;
        }

        long long ans = nums[0];
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }
        return ans;
    }
};