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
#define ull long long

int main()
{
    fio;
    int N = 3;                                // 工作表 A B X
    vector<vector<int>> g(N, vector<int>(N)); // .表示清澈，#表示黑色
    for (int i = 0; i < N; i++)
    {
        int N1, M1;
        cin >> N1 >> M1;
        vector<vector<char>> g1(N1, vector<char>(M1));
        for (int j = 0; j < N1; j++)
        {
            string s;
            cin >> s;
            for (int k = 0; k < M1; k++)
            {
                g1[j][k] = s[k];
            }
        }
    }
    // 从工作表A和B中的黑色方块创建 X 工作表，再给一张无限大的清澈的工作表C：
    // 1. 沿着网格将A和B纸片粘贴到C纸片上。每张纸可以通过平移粘贴到任何地方，但不能剪切或旋转。
    // 2.从C纸上沿网格切出一个Hx * Wx区域。在这里，如果粘贴了A或B表的黑色方块，那么切出的表的一个方块将是黑色的，否则就是透明的。

    // 判断高桥是否能通过适当地选择粘贴纸片的位置和切出的区域来实现他的目标，也就是说、
    // 他是否能满足以下两个条件。
    // 切出的纸张包括纸张A和B的所有黑色方块，纸张A和B的黑色方块可能在切出的纸张上重叠。
    // 切出的纸片与_X纸片重合，不需要旋转或翻转。

      
      
       
    return 0;
}
