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

using namespace std;
#include <bits/stdc++.h>

const int MAXN = 35;
int father[MAXN]; // 记录父节点
int CNT;          // 顶点数

const int N = 500 + 5;
int head[N];
int cnt; // 连通分量
int find(int x)
{
  if (x == head[x])
    return x;
  return find(head[x]);
}
void connect(int a, int b)
{
  int fa = find(a);
  int fb = find(b);
  if (fa == fb)
    return;
  head[fa] = fb;
  cnt--;
}
void init(int n)
{
  for (int i = 0; i < n; i++)
    head[i] = i;
}

int dirt[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 右左下上

class Solution
{
public:
  bool equationsPossible(vector<string> &eq)
  {

    init(26);

    vector<pair<int, int>> neq = {};

    rep(i, 0, eq.size() - 1)
    {

      int a = eq[i][0] - 'a';
      int b = eq[i][3] - 'a';
      string op = eq[i].substr(1, 2);
      if (op == "==")
      {
        connect(a, b);
      }
      else if (op == "!=")
      {
        neq.push_back({a, b});
      }
    }

    for (auto p : neq)
    {
      int a = p.first;
      int b = p.second;
      if (find(a) == find(b))
        return false;
    }

    return true;
  }
};

// ——————————————————————————————————————————————————————————————————————

#include "lib/testIO.h"

#include "lib/testIO.h"
int main()
{
  REGISTER_CONSTRUCTOR_SOLUTION;
  REGISTER_MEMBERFUNCTION_SOLUTION(equationsPossible);
  while (true)
  {
    executor.constructSolution();
    executor.executeSolution();
  }
}