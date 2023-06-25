//
// Created by w1z4Rd on 2022/10/30.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    /**
     * 欧几里得算法
     * 求两个正整数的最大公约数
     * @param a
     * @param b
     * @return
     */
    int gcd(int a, int b)
    {
        return b ? gcd(b, a % b) : a;
    }

    /**
     * 扩展欧几里得算法
     *
     * 裴蜀定理：若 a,b 是整数,且 (a,b)=d，那么对于任意的整数 x,y,ax+by 都一定是 d 的倍数，特别地，一定存在整数 x,y，使 ax+by=d 成立。
     * 扩展欧几里得算法可以在 O(logn) 的时间复杂度内求出系数 x,y
     * @param nums
     * @return
     */
    int exgcd(int a, int b, int &x, int &y)
    {
        if (!b)
        {
            x = 1;
            y = 0;
            return a;
        }
        int d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }

    /**
     * 线性筛素数
     * 可以在 O(n) 的时间复杂度内求出 1∼n 之间的所有质数。
     */
    int N = 1000;
    int primes[N], cnt;
    bool st[N];
    void get_primes(int n)
    {
        for (int i = 2; i <= n; i++)
        {
            if (!st[i])
                primes[cnt++] = i; // i 是质数
            for (int j = 0; primes[j] <= n / i; j++)
            {
                st[primes[j] * i] = true;
                if (i % primes[j] == 0)
                    break;
            }
        }
    }

    /**
     * 欧拉函数
     * 求 1∼n 之间与 n 互质的数的个数
     * @param n
     * @return
     */
    int phi(int n)
    {
        int res = n;
        for (int i = 2; i <= n / i; i++)
            if (n % i == 0)
            {
                res = res / i * (i - 1);
                while (n % i == 0)
                    n /= i;
            }
        if (n > 1)
            res = res / n * (n - 1);
        return res;
    }

    /**
     * 同余定理
     * 两个整数 a,b 以及一个正整数 p，如果 a 等于 b 模 p，则称 a 与 b 同余，记作 a≡b(mod p)。
     * 由于同余关系是等价关系，因此同余关系可以用来判断两个整数是否等价。
     */

    /**
     * 埃氏筛，求出所有素数
     * 在筛质数时，我们会发现，筛去2后，2的倍数4、6、8等一定不是素数;筛去3后，3的倍数6、9、12等一定不是倍数。
     */
    bool prime[100000];
    void ai()
    {
        memset(prime, 1, sizeof(prime)); // 埃筛一定要初始化数组值, 把每个数都设为合数
        for (int i = 2; i <= 100000; ++i)
            prime[i] = 1;
        for (int i = 2; i <= 100000; ++i)
            if (prime[i])
                for (int j = i * 2; j <= 100000; j += i) // 从i*i开始筛，将i的倍数筛去
                    prime[j] = 0;
    }

    /**
     * 线性筛，求出所有素数
     * 原理：线性筛的核心思想是，对于每个质数，筛去它的所有倍数。
     * 但是这样会导致重复筛去，比如 2 和 3 都会筛去 6，因此我们需要记录每个数最小的质因子，从而避免重复筛去。
     * 例如，对于 6，我们知道它最小的质因子（质因子：能被质数整除的数）是 2，那么我们就可以从 2×6 开始筛去，而不是从 6 开始筛去。
     */
    int prime[100000]; // 存储所有素数
    int cnt;           // 素数个数
    bool st[100000];   // st[i] = true表示i是合数
    void linear()
    {
        for (int i = 2; i <= 100000; ++i) // 从2开始筛
        {
            if (!st[i])                                  // 如果i是质数
                prime[cnt++] = i;                        // i是质数
            for (int j = 0; prime[j] <= 100000 / i; ++j) // prime[j] <= i是为了防止重复筛去
            {
                st[prime[j] * i] = true; // prime[j] * i是合数
                if (i % prime[j] == 0)   // i是prime[j]的倍数
                    break;
            }
        }
    }

    // 是否为质数
    bool isPrime(long long target)
    {
        int i = 0;
        if (target <= 1)
        {
            printf("illegal input!\n"); // 素数定义
            return false;
        }
        for (i = 2; i <= target / 2; i++)
        {
            if (target % i == 0)
                return false;
        }
        return true;
    }

    /**
     *  判断是否为质数, 判断依据：如果一个数不是质数，那么它一定可以分解成两个数的乘积，其中一个数一定小于等于它的平方根，另一个数一定大于等于它的平方根。
     */
    bool isPrime(int x)
    {
        if (x == 1)
            return false;
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    // 阶乘
    int f(int x)
    {
        if (x == 1)
            return 1;
        return x * f(x - 1);
    }

    /**
     * 分解质因数，输出x的所有质因子
     * 6: 2、3
     * 10: 2、5
     */
    void get_factors(int x)
    {
        for (int i = 2; i <= x / i; i++)
        {
            if (x % i == 0)
            {
                int s = 0;
                while (x % i == 0)
                {
                    x /= i;
                    s++;
                }
                printf("%d %d\n", i, s);
            }
        }
        if (x > 1)
            printf("%d %d\n", x, 1);
        puts("");
    }
};