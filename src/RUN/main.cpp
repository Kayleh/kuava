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
#define changeCase(c) (c ^ (1 << 5)) // 大小写互换
#define isLetter(c) (isalpha(c))     // 判断是否为字母
#define INF 0x3f3f3f3f               // 无穷大
#define NINF 0xc0c0c0c0              // 无穷小
#define randd(a, b) (rand() % (b - a + 1) + a)
// [a, b]
#define ALL(x) x.begin(), x.end()
#define fio                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);
//__builtin_popcountll 用于计算一个数的二进制中1的个数

template <class T>
inline void ckmin(T &a, T b)
{
    a = min(a, b);
}

template <class T>
inline void ckmax(T &a, T b)
{
    a = max(a, b);
}

template <class T>
void COPY(T a[], const T b[], int n)
{
    memcpy(a, b, n * sizeof(T));
}

void SET(int a[], int val, int n)
{
    memset(a, val, n * sizeof(int));
}

using namespace std;

//@start——————————————————————————————————————————————————————————————————————

int main()
{
    fio;
    cout << "Hello World!" << endl;
}