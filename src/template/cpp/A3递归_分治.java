/*
 *  $ codeforce  2022-08-20
 *
 *  Copyright 2022  Kayleh. All rights reserved.
 *  @see {@link https://github.com/Kayleh/kuava}
 *
 */

package template.cpp;

/**
 * Recursion
 * 递归代码最重要的两个特征：结束条件和自我调用。自我调用是在解决子问题，而结束条件定义了最简子问题的答案。
 * <p>
 * int func(传入数值) {
 * if (终止条件) return 最小子问题解;
 * return func(缩小规模);
 * }
 */
public class A3递归_分治 {

    /* Recursion 递归 */

    /**
     * @param n
     * @return
     * @brief 求阶乘
     * <p>
     * 递归求阶乘。
     * <p>
     * e.g.求 5! = 5 * 4 * 3 * 2 * 1 = 120
     */
    public static long factorial(long n) {
        if (n == 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }


    /* Divide and Conquer 分治 */

    /**
     * 分治算法的核心思想就是「分而治之」。
     * <p>
     * 大概的流程可以分为三步：分解 -> 解决 -> 合并。
     * - 分解原问题为结构相同的子问题。
     * - 分解到某个容易求解的边界之后，进行递归求解。
     * - 将子问题的解合并成原问题的解。
     */
    /*void merge_sort(一个数组) {
        if (可以很容易处理) return;
        merge_sort(左半个数组);
        merge_sort(右半个数组);
        merge(左半个数组, 右半个数组);
    }*/
    public static void main(String[] args) {
        System.out.println(factorial(5));
        System.out.println(factorial(25));
    }

}
