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

class Solution
{
public:
  int minimumCost(string s)
  {
    int n = s.size();
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '?')
        cnt++;
      else
      {
        if (i > 0 && s[i - 1] == '?')
        {
          if (s[i] == s[i - 1])
            ans += 2;
          else
            ans += 1;
        }
      }
    }
    if (cnt == 0)
      return ans;
    if (cnt % 2 == 1)
      return -1;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '?')
      {
        if (i > 0 && s[i - 1] == '?')
        {
          if (l < r)
          {
            s[i] = ')';
            r++;
          }
          else
          {
            s[i] = '(';
            l++;
          }
        }
        else
        {
          if (l < r)
          {
            s[i] = '(';
            l++;
          }
          else
          {
            s[i] = ')';
            r++;
          }
        }
      }
    }
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '(')
        cnt1++;
      else
        cnt1--;
      if (cnt1 < 0)
        return -1;
    }
    return ans + cnt / 2 * 2;
  }
};

// ——————————————————————————————————————————————————————————————————————

#include "lib/testIO.h"

int main()
{
  REGISTER_CONSTRUCTOR_SOLUTION;
  REGISTER_MEMBERFUNCTION_SOLUTION(minimumCost);
  while (true)
  {
    executor.constructSolution();
    executor.executeSolution();
  }
}