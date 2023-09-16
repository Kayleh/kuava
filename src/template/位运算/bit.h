#include <bits/stdc++.h>

using namespace std;

/**
 * 左移
 * @return  num 左移 shift 位
 */
int leftShift(int num, int shift)
{
    return num << shift;
}

/**
 * 右移
 * @return  num 右移 shift 位
 */
int rightShift(int num, int shift)
{
    return num >> shift;
}

/**
 * 按位与
 * @return  num1 与 num2 的位与 (如果有一个为 0 则为 0)
 */
int bitAnd(int num1, int num2) { return num1 & num2; }

/**
 * 按位或
 * @return  num1 与 num2 的位或 (如果有一个为 1 则为 1)
 */
int bitOr(int num1, int num2) { return num1 | num2; }

/**
 * 按位异或
 * @return  num1 与 num2 的位异或 (如果相同则为 0，不同则为 1)
 */
int bitXor(int num1, int num2) { return num1 ^ num2; }

/**
 * 按位取反
 * @return  num 的按位取反 (0 变 1，1 变 0)
 */
int bitNot(int num) { return ~num; }

/**
 * 判断 num 的第 pos 位是否为 1
 * @return  num 的第 pos 位是否为 1
 */
bool isOne(int num, int pos) { return (num >> pos) & 1; }

/**
 * 交换两个数
 * @brief swap
 */
void swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

/**
 *
 * @brief lowbit
 * @param num
 * @return  num 的二进制表示中，最低位的 1 的位置。
 */
int lowbit(int num)
{
    return num & (-num);
}
