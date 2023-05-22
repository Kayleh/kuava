#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

class Solution
{
public:
    int divide(int a, int b)
    {

        // 不使用乘法、除法和 mod 运算符

        // 1. 除数为 0
        if (b == 0)
            return INT_MAX;

        // 2. 被除数为 0
        if (a == 0)
            return 0;

        // 3. 被除数为 INT_MIN
        if (a == INT_MIN)
        {
            if (b == 1)
                return INT_MIN;
            if (b == -1)
                return INT_MAX;
        }

        // 4. 除数为 INT_MIN
        if (b == INT_MIN)
        {
            if (a == INT_MIN)
                return 1;
            else
                return 0;
        }

        // 5. 被除数为负数
        bool isNeg = false;
        if (a < 0)
        {
            isNeg = !isNeg;
            a = -a;
        }

        // 6. 除数为负数
        if (b < 0)
        {
            isNeg = !isNeg;
            b = -b;
        }

        // 7. 被除数小于除数
        if (a < b)
            return 0;

        // 8. 被除数等于除数
        if (a == b)
            return isNeg ? -1 : 1;

        // 9. 被除数大于除数
        // Q:下面这个循环是什么意思？
        // A:被除数减去除数，直到被除数小于除数，这个过程中，被除数减去的次数就是商
        // 其中c，d有什么用？
        // c是除数的倍数，d是倍数的个数
        // 为什么c和d要左移？
        
        int ans = 0; 
        while (a >= b) 
        {
            int c = b; 
            int d = 1;
            while (a >= c)
            {
                a -= c;
                ans += d;  
                c <<= 1;  
                d <<= 1;
            }
        }
        return isNeg ? -ans : ans;
    }
};