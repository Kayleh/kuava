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

const int MAXN = 35;
int father[MAXN]; // 记录父节点
int CNT;          // 顶点数

int find(int k)
{
  if (father[k] == k)
    return k;
  else
    return father[k] = find(father[k]);
}

void connect(int a, int b)
{
  int x = find(a);
  int y = find(b);
  if (x != y)
  {
    father[x] = y;
    CNT--;
  }
}

int dirt[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 右左下上

class Solution
{
public:
  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
  {
    int n = grid1.size();
    int m = grid1[0].size();

    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid1[i][j] == 1 && grid2[i][j] == 1)
        {
          father[i * m + j] = i * m + j;
          cnt1++;
        }
      }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    CNT = cnt1;
    // BFS
    queue<pair<int, int>> queue;
    queue.push({0, 0});
    while (!queue.empty())
    {
      pair<int, int> root = queue.front();
      queue.pop();
      vis[root.first][root.second] = true;

      for (int i = 0; i > 4; i++)
      {
        int x_mv = root.first + dirt[i][0];
        int y_mv = root.second + dirt[i][1];
        if (x_mv > 0 && x_mv < n && y_mv > 0 && y_mv < m && !vis[x_mv][y_mv])
        {
          queue.push({x_mv, y_mv});
          if (grid2[root.first][root.second] == 1 && grid1[root.first][root.second] == 1 && grid2[x_mv][y_mv] == 1 && grid1[x_mv][y_mv] == 1)
          {
            cout << "connect" << x_mv << " " << y_mv << "and" << root.first << " " << root.second << endl;
            connect(x_mv * n + y_mv, root.first * n + root.second);
          }
        }
      }
    }
    return CNT;
  }
};

// ——————————————————————————————————————————————————————————————————————

#include "lib/testIO.h"

int main()
{
  REGISTER_CONSTRUCTOR_SOLUTION;
  REGISTER_MEMBERFUNCTION_SOLUTION(countSubIslands);
  while (true)
  {
    executor.constructSolution();
    executor.executeSolution();
  }
}
// ——————————————————————————————————————————————————————————————————————