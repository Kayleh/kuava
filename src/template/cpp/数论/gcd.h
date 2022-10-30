//
// Created by w1z4Rd on 2022/10/30.
//

#include <iostream>

using namespace std;

class Solution {

public:
    /**
     * 欧几里得算法
     * 求两个正整数的最大公约数
     * @param a
     * @param b
     * @return
     */
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    /**
     * 扩展欧几里得算法
     *
     * @param nums
     * @return
     */
    int exgcd(int a, int b, int &x, int &y) {
        if (!b) {
            x = 1;
            y = 0;
            return a;
        }
        int d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }
};