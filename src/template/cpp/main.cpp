//
// Created by w1z4Rd on 2022/10/27.
//

//#include "Solution.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>
//#include <cassert>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define PI 3.14159265358979323846
#define gcd(a, b) __gcd(a, b)                             // 最大公约数
#define bitcount(a) __builtin_popcount(a)                 // 二进制中1的个数
#define lcm(a, b) (a * b / gcd(a, b))                     // 最小公倍数
#define max(a, b) (a > b ? a : b)                         // 最大值
#define min(a, b) (a < b ? a : b)                         // 最小值
#define abs(a) (a > 0 ? a : -a)                           // 绝对值
#define swap(a, b) (a ^= b; b ^= a; a ^= b)               // 交换
#define forin(item, arr) for (auto item : arr)            // 遍历
#define rep(i, from, to) for (int i = from; i <= to; i++) // 递增
#define per(i, from, to) for (int i = from; i >= to; i--) // 递减
#define ll long long
#define ull unsigned long long
#define changeCase(c) (c ^ (1 << 5)) // 大小写互换
#define isLetter(c) (isalpha(c))     // 判断是否为字母
#define INF 0x3f3f3f3f               // 无穷大
#define NINF 0xc0c0c0c0              // 无穷小
/*struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};*/

using namespace std;

ll gao(ll a)
{
    if (a == 1)
    {
        return 1;
    }
    return a * gao(a - 1); 
}
int n;
int main(int argc, char const *argv[])
{
    cin >> n;
    cout << gao(n);
    return 0;
}
