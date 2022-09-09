/*
 *  $ codeforce  2022-08-20
 *
 *  Copyright 2022  Kayleh. All rights reserved.
 *  @see {@link https://github.com/Kayleh/kuava}
 *
 */

package template.Java.a算法基础.A3递归_分治;

import template.Java.eg.路径总和III;
import template.Java.struct.Tree.NTreeNode;
import template.Java.struct.Tree.TreeNode;

import java.util.List;

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
    // (写递归的要点明白一个函数的作用并相信它能完成这个任务，千万不要跳进这个函数里面企图探究更多细节， 否则就会陷入无穷的细节无法自拔，人脑能压几个栈啊。)

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

    /**
     * 遍历一颗二叉树
     */
    void traverse(TreeNode root) {
        if (root == null) return;
        traverse(root.left);
        traverse(root.right);
    }

    /**
     * 遍历一颗N叉树
     */
    void traverse(NTreeNode root) {
        if (root == null) return;
        List<NTreeNode> children = root.children;
        for (NTreeNode child : children) {
            traverse(child);
        }
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
    void merge_sort(int[] arr) {
        /*if (可以很容易处理) return;
        merge_sort(左半个数组);
        merge_sort(右半个数组);
        merge(左半个数组, 右半个数组);*/
    }


    /**
     * e.g.
     *
     * @see template.Java.eg.路径总和III
     */
    路径总和III test;
}
