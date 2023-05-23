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
template <class T>
inline void ckmin(T &a, T b) { a = min(a, b); }
template <class T>
inline void ckmax(T &a, T b) { a = max(a, b); }
template <class T>
void COPY(T a[], const T b[], int n) { memcpy(a, b, n * sizeof(T)); }

// 转二进制字符串
#define toBinary(x) bitset<8 * sizeof(x)>((x)).to_string()

/* template <class T>
inline void MEMSET(T a, int b) { memset(a, b, sizeof(a)); } */

// auto cmpp = [](const pair<int, int> &a, const pair<int, int> &b)
//{ return a.second < b.second; };

using namespace std;
#include <bits/stdc++.h>
#include "lib/testIO.h"

//@start——————————————————————————————————————————————————————————————————————

class Solution
{
public:
  bool isBipartite(vector<vector<int>> &graph)
  {

    int N = graph.size();     // 顶点数
    vector<int> colors(N, 0); // 未染色为0，染色为1，染色为2

    /**
     * @brief 深度优先搜索，将当前顶点染成color，将与当前顶点相邻的顶点染成-color。这样就可以保证相邻的顶点颜色不同。如果相邻的顶点都不同，说明是二分图。
     * @param cur 当前顶点
     * @param color 当前顶点需要染的颜色
     */
    function<bool(int, int)> dfs = [&](int cur, int color) -> bool
    {
      if (colors[cur] != 0)
        return colors[cur] == color; // 已经染色，判断是否为color
      colors[cur] = color;           // 染色

      vector<int> edges = graph[cur];
      for (int i = 0; i < edges.size(); i++)
      {
        if (!dfs(edges[i], -color))
          return false;
      }
      return true;
    };

    // 因为可能存在多个连通分量，所以需要遍历每个顶点，从每个顶点开始染色
    for (int i = 0; i < N; i++)
    {
      if (colors[i] == 0 && !dfs(i, 1))
        return false;
    }
    return true;
  }
};

//@end——————————————————————————————————————————————————————————————————————

int main()
{
  REGISTER_CONSTRUCTOR_SOLUTION;
  REGISTER_MEMBERFUNCTION_SOLUTION(isBipartite);
  while (true)
  {
    executor.constructSolution();
    executor.executeSolution();
  }
}