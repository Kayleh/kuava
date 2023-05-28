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

/**
给你一个下标从 0 开始的整数数组 nums ，
你可以在一些下标之间遍历。对于两个下标 i 和 j（i != j），当且仅当 gcd(nums[i], nums[j]) > 1 时，我们可以在两个下标之间通行，其中 gcd 是两个数的 最大公约数 。

你需要判断 nums 数组中 任意 两个满足 i < j 的下标 i 和 j ，是否存在若干次通行可以从 i 遍历到 j 。

如果任意满足条件的下标对都可以遍历，那么返回 true ，否则返回 false 。
*/

int fa[100005];
int ranks[100005];
int find(int x)
{
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
  int fx = find(x), fy = find(y);
  if (fx == fy)
    return;
  if (ranks[fx] < ranks[fy])
  {
    swap(fx, fy);
  }
  fa[fy] = fx;
  ranks[fx] += ranks[fy];
}
class Solution
{
public:
  bool canTraverseAllPairs(vector<int> &nums)
  {
    // 并查集
    int n = nums.size();
    iota(fa, fa + n, 0);
    fill(ranks, ranks + n, 1);

    vector<int> tmp;
    for (int i = 0; i < n; i++)
    {
      // 把每个数和它的因子合并（因子是指能整除它的数）
      for (int j = 2; j * j <= nums[i]; j++)
      {
        if (nums[i] % j == 0)
        {
          tmp.push_back(j);
          tmp.push_back(nums[i] / j);
        }
      }
    }

    // 把因子也加入并查集
    for (int i = 0; i < tmp.size(); i++)
    {
      merge(tmp[i], tmp[0]);
    }
    

    for (int i = 0; i < n; i++)
    {
      // 如果有两个数不在同一个集合，说明不能遍历
      if (find(i) != find(0))
        return false;
    }

    return true;
  }
};

// ——————————————————————————————————————————————————————————————————————
#include "lib/testIO.h"

int main()
{
  REGISTER_CONSTRUCTOR_SOLUTION;
  REGISTER_MEMBERFUNCTION_SOLUTION(canTraverseAllPairs);
  while (true)
  {
    executor.constructSolution();
    executor.executeSolution();
  }
}