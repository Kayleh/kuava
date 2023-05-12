//
// Created by w1z4Rd on 2022/10/30.
//

#include <iostream>

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
};