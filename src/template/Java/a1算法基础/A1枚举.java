/*
 *  $ codeforce  2022-08-20
 *
 *  Copyright 2022  Kayleh. All rights reserved.
 *  @see {@link https://github.com/Kayleh/kuava}
 *
 */

package template.Java.a1算法基础;

public class A1枚举 {
    /* code */

    /**
     * @brief 枚举
     * <p>
     * 基于已有知识来猜测答案的一种问题求解策略。
     * 枚举的思想是不断地猜测，从可能的集合中一一尝试，然后再判断题目的条件是否成立。
     * <p>
     * e.g.一个数组中的数互不相同，求其中和为 0 的数对的个数。
     */

    public static void main(String[] args) {
        int[] a = {1, 2, -1, -2, 5};
        int len = a.length;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (a[i] + a[j] == 0) {
                    System.out.println(a[i] + " " + a[j]);
                }
            }
        }
    }
}
