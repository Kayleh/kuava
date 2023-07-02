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
#define swapp(a, b) (a ^= b; b ^= a; a ^= b)
#define forin(item, arr) for (auto item : arr)
#define rep(i, from, to) for (int i = from; i <= to; i++)
#define dep(i, from, to) for (int i = from; i >= to; i--)
#define ll long long
#define ull unsigned long long
#define ld long double
#define changeCase(c) (c ^ (1 << 5))           // 大小写互换
#define isLetter(c) (isalpha(c))               // 判断是否为字母
#define INF 0x3f3f3f3f                         // 无穷大
#define NINF 0xc0c0c0c0                        // 无穷小
#define randd(a, b) (rand() % (b - a + 1) + a) // [a, b]
#define all(x) (x).begin(), (x).end()
#define fio                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);
//__builtin_popcountll 用于计算一个数的二进制中1的个数
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

template <class T>
inline void ckmin(T &a, T b)
{
    a = min(a, b);
}

template <class T>
inline void ckmax(T &a, T b) { a = max(a, b); }

template <class T>
void COPY(T a[], const T b[], int n) { memcpy(a, b, n * sizeof(T)); }

void SET(int a[], int val, int n) { memset(a, val, n * sizeof(int)); }

using namespace std;

#include <bits/stdc++.h>

/**
 * 给定一个长度为 N 的字符串 S，由小写英文字母组成。确定是否可以将 S 分成两个或多个连续的子串，使它们严格按字典顺序递增。
 * 准确的说，判断是否存在满足以下所有条件的字符串序列∨ = (t1, ta, . . - , t)。 « 序列 k 的长度至少为 2。 « tiisnotempty.(1 < i < k) « 连接 t1, a, . - . , t 按此顺序产生 S。 « 按词典顺序小于 t; 。对于每个整数 i，使得 1 < i < k。给你T个测试用例。找出每个问题的答案
 */

int main()
{
    fio;
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        string s;
        cin >> s;
        cout << "Case #" << s << ": " << endl;
        // 判断s是否能够被分割成多个子串，使得子串严格按照字典序递增, 每个子串的长度至少为2
        // 贪心算法
        // 从左到右遍历，如果当前字符比前一个字符小，那么就可以将当前字符加入到前一个字符组成的子串中

        int len = s.length();
        string ans = "";
        ans += s[0];
        for (int i = 1; i < len; i++)
        {
            if (s[i] >= s[i - 1])
            {
                ans += s[i];
            }
            else
            {
                ans = s[i] + ans;
            }
        }

        cout << ans << endl;

        // << "Yes" << endl;
    }

    return 0;
}
