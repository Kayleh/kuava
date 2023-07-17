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

/*

AtCoder Shop 有 N 个产品。第 i 个产品 (1 < i < N) 的价格为 P；。
第 i 个产品 (1 < i < N) 有 C 功能。
第 i 个产品 (1 < i < N) 的第 j 个功能 (1 < j < C}) 表示为整数 F； j 介于 1 和 M 之间（含）。

高桥想知道是否有一种产品完全优于另一种产品。如果有 i 和 j ( 1 <= i, j <= N) 使得第 i 个和第 j 个产品满足以下所有条件，则打印 Yes；否则，打印No

- pi >= pj
- 第j个产品包含第i个产品的所有功能
*/
int N; // N 个产品
struct Node
{
    int P;
    vector<int> F;
};
vector<Node> nodes;

/**
 * 判断j是否完全超过i，或i是否完全超过j
 */
bool isSuperior(Node &i, Node &j)
{
    // 如果功能一样，价格不同，就是完全超过
    // 如果（价格一样），其中一个的功能是另一个的子集，就是完全超过
    bool bigJ = includes(all(i.F), all(j.F));
    bool bigI = includes(all(j.F), all(i.F));
    if (bigI && i.P > j.P)
    { // i的功能是j的子集,且i的价格大于j的价格
        return true;
    }

    if (bigJ && i.P < j.P)
    {
        return true;
    }
    if (i.P == j.P)
    {
        if (bigI && j.F.size() > i.F.size())
        {
            return true;
        }
        if (bigJ && i.F.size() > j.F.size())
        {
            return true;
        }
    }
    return false;
}

int M; // M 个功能

int main()
{
    fio;
    cin >> N >> M;
    nodes.resize(N);
    for (int i = 0; i < N; i++)
    {
        nodes[i].F = vector<int>();
    }
    for (int i = 0; i < N; i++)
    {
        cin >> nodes[i].P;
        int c;
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            int f;
            cin >> f;
            nodes[i].F.push_back(f);
        }
    }

    // 价格从大到小排序
    sort(all(nodes), [](const Node &a, const Node &b)
         { return a.P > b.P; });

    // 从大到小，如果j完全超过i，就是完全超过
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (isSuperior(nodes[i], nodes[j]))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
