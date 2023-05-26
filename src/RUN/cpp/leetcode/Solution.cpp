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

class DsuFind
{
private:
  vector<int> father;
  vector<int> rank;
  int cnt = 0;

public:
  DsuFind(int n)
  {
    father.resize(n);
    rank.resize(n);
    cnt = n;
    for (int i = 0; i < n; i++)
    {
      father[i] = i;
      rank[i] = 1;
    }
  }

  int find(int a)
  {
    while (father[a] != a)
    {
        father[a] = father[father[a]];
        a = father[a];
    }
    return a;
  }

  int getCnt(){
    return cnt;
  }

  void conntect(int a, int b)
  {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb)
      return;
    int rka = rank[a];
    int rkb = rank[b];
    if (rka > rkb)
    {
      father[rb] = ra;
      rank[ra] += rank[rb];
    }
    else
    {
      father[ra] = rb;
      rank[rb] += rank[ra];
    }
    cnt--;
  }
};

class Solution
{
public:
  int removeStones(vector<vector<int>> &stones)
  {
    int n = stones.size();
    DsuFind uf(n);
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
        {
          uf.conntect(i, j);
        }
      }
    }
    return n - uf.getCnt();
  }
};

// ——————————————————————————————————————————————————————————————————————
#include "lib/testIO.h"

int main()
{
  REGISTER_CONSTRUCTOR_SOLUTION;
  REGISTER_MEMBERFUNCTION_SOLUTION(solve);
  while (true)
  {
    executor.constructSolution();
    executor.executeSolution();
  }
}