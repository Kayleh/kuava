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

#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>
#include <unordered_set>

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

//@start——————————————————————————————————————————————————————————————————————

class UnionFind
{
public:
  vector<int> parent;

  UnionFind(int n)
  {
    parent.resize(n);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }

  void unionSet(int index1, int index2)
  {
    parent[find(index2)] = find(index1);
  }

  int find(int index)
  {
    if (parent[index] != index)
    {
      parent[index] = find(parent[index]);
    }
    return parent[index];
  }
};

class Solution
{
public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
  {
    map<string, int> emailToIndex;
    map<string, string> emailToName;
    int emailsCount = 0;
    for (auto &account : accounts)
    {
      string &name = account[0];
      int size = account.size();
      for (int i = 1; i < size; i++)
      {
        string &email = account[i];
        if (!emailToIndex.count(email))
        {
          emailToIndex[email] = emailsCount++;
          emailToName[email] = name;
        }
      }
    }
    UnionFind uf(emailsCount);
    for (auto &account : accounts)
    {
      string &firstEmail = account[1];
      int firstIndex = emailToIndex[firstEmail];
      int size = account.size();
      for (int i = 2; i < size; i++)
      {
        string &nextEmail = account[i];
        int nextIndex = emailToIndex[nextEmail];
        uf.unionSet(firstIndex, nextIndex);
      }
    }
    map<int, vector<string>> indexToEmails;
    for (auto &[email, _] : emailToIndex)
    {
      int index = uf.find(emailToIndex[email]);
      vector<string> &account = indexToEmails[index];
      account.emplace_back(email);
      indexToEmails[index] = account;
    }
    vector<vector<string>> merged;
    for (auto &[_, emails] : indexToEmails)
    {
      sort(emails.begin(), emails.end());
      string &name = emailToName[emails[0]];
      vector<string> account;
      account.emplace_back(name);
      for (auto &email : emails)
      {
        account.emplace_back(email);
      }
      merged.emplace_back(account);
    }
    return merged;
  }
};

//@end——————————————————————————————————————————————————————————————————————