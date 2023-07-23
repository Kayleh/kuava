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

vector<vector<int>> graph;
vector<bool> visited;
vector<int> cycle; // 存储找到的环上的点
bool foundCycle = false;

void dfs(int node)
{
    visited[node] = true;
    cycle.push_back(node);

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
        else if (!foundCycle)
        {
            // 找到环上的点
            int startIndex = cycle.size() - 1;
            while (cycle[startIndex] != neighbor)
            {
                startIndex--;
            }
            foundCycle = true;
            cout << cycle.size() - startIndex << endl;
            for (int i = startIndex; i < cycle.size(); ++i)
            {
                cout << cycle[i] + 1 << " ";
            }
            cout << endl;
        }
    }

    cycle.pop_back();
}

int main()
{
    int n;
    cin >> n;

    // 初始化图的大小和visited数组
    graph.resize(n);
    visited.resize(n, false);

    // 读取边的信息并构建图
    for (int i = 0; i < n; ++i)
    {
        int to;
        cin >> to;
        graph[i].push_back(to - 1);
    }

    // 遍历每个未访问的节点，找到环上的点
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    return 0;
}