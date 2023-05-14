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

// #include "Solution.h"
#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>
// #include <cassert>
#include <unordered_set>

#ifdef kOS
#define INPUT_FILE "C:/input.txt"
#define OUTPUT_FILE "C:/output.txt"
#endif

#define PI 3.14159265358979323846
#define gcd(a, b) __gcd(a, b)							  // 最大公约数
#define bitcount(a) __builtin_popcount(a)				  // 二进制中1的个数
#define lcm(a, b) (a * b / gcd(a, b))					  // 最小公倍数
#define max(a, b) (a > b ? a : b)						  // 最大值
#define swapp(a, b) (a ^= b; b ^= a; a ^= b)			  // 交换
#define forin(item, arr) for (auto item : arr)			  // 遍历
#define rep(i, from, to) for (int i = from; i <= to; i++) // 递增
#define per(i, from, to) for (int i = from; i >= to; i--) // 递减
#define ll long long
#define ull unsigned long long
#define changeCase(c) (c ^ (1 << 5))		   // 大小写互换
#define isLetter(c) (isalpha(c))			   // 判断是否为字母
#define INF 0x3f3f3f3f						   // 无穷大
#define NINF 0xc0c0c0c0						   // 无穷小
#define randd(a, b) (rand() % (b - a + 1) + a) // [a, b]

template <class T>
inline void ckmin(T &a, T b) { a = min(a, b); }
template <class T>
inline void ckmax(T &a, T b) { a = max(a, b); }
template <class T>
void COPY(T a[], const T b[], int n) { memcpy(a, b, n * sizeof(T)); }
void SET(int a[], int val, int n) { memset(a, val, n * sizeof(int)); }

using namespace std;

//@start——————————————————————————————————————————————————————————————————————
// #define debug

bool ok(int n, int m)
{
	if (n == m)
	{
		return true; 
	}
	else if (n % 3 != 0)
	{
		return false;
	}
	else
	{
		return (ok(n / 3, m) || ok(2 * n / 3, m)); // 递归，分别除以3和2/3
	}
}

void Solution()
{
	int n, m;
	cin >> n >> m;
	cout << (ok(n, m) ? "YES" : "NO") << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int i = 1; i <= tt; i++)
	{
		Solution();
	}
}

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