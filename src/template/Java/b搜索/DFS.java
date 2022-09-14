/*
 *  $ codeforce  2022-09-05
 *
 *  Copyright 2022  Kayleh. All rights reserved.
 *  @see {@link https://github.com/Kayleh/kuava}
 *
 */
package template.Java.b搜索;

import java.util.Arrays;
import java.util.Scanner;

public class DFS {
    /**
     * 在 搜索算法 中，该词常常指利用递归函数方便地实现暴力枚举的算法
     */

    /**
     * e.g.把正整数 n 分解为 3 个不同的正整数，如 6=1+2+3，排在后面的数必须大于等于前面的数，输出所有方案。
     * DFS搜索算法的特点在于，将要搜索的目标分成若干「层」，每层基于前几层的状态进行决策，直到达到目标状态。
     */

    /**
     * C++ Version
     *
     * <p> for (int i = 1; i <= n; ++i){
     * <p>  for (int j = i; j <= n; ++j){
     * <p>     for (int k = j; k <= n; ++k){
     * <p>       if (i + j + k == n) printf("%d = %d + %d + %d\n", n, i, j, k);
     * <p>     }
     * <p>  }
     * <p>}
     */

    int m = 3;
    int arr[] = new int[103];

    public void Solution() {
        Scanner in = new Scanner(System.in);
        int target = in.nextInt();
        dfs(target, 1, 1);
    }

    /**
     * 从第 index 个数开始，枚举所有可能取值
     *
     * @param target 目标值
     * @param index  当前枚举到第几个数
     * @param start  当前数的最小取值
     */
    void dfs(int target, int index, int start) {
        if (target == 0) {
            for (int j = 1; j <= index - 1; ++j) {
                System.out.print(arr[j] + " ");
            }
            System.out.println();
        }
        if (index <= m) {
            for (int j = start; j <= target; ++j) {
                arr[index] = j;
                dfs(target - j, index + 1, j);  // 请仔细思考该行含义。
                //arr[index] = 0;
            }
        }
    }

    public static void main(String[] args) {
        DFS dfs = new DFS();
        dfs.Solution();
    }


}


