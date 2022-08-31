/*
 *  $ codeforce  2022-08-30
 *
 *  Copyright 2022  Kayleh. All rights reserved.
 *  @see {@link https://github.com/Kayleh/kuava}
 *
 */

package template.Java.a1算法基础.A6前缀和_差分;


public class A6前缀和_差分 {
    /**
     * @brief 前缀和
     * <p>
     * prefix[i] 就代表着 nums[0..i-1] 所有元素的累加和，
     * 如果我们想求区间 nums[i..j] 的累加和，只要计算 prefix[j+1] - prefix[i] 即可，
     * 而不需要遍历整个区间求和。
     */
    class PrefixSum {
        // 前缀和数组
        private int[] prefix;

        public PrefixSum(int[] nums) {
            prefix = new int[nums.length + 1];
            // 计算 nums 的累加和
            for (int i = 1; i < prefix.length; i++) {
                prefix[i] = prefix[i - 1] + nums[i - 1];
            }
        }

        /* 查询闭区间 [i, j] 的累加和 */
        public int query(int i, int j) {
            return prefix[j + 1] - prefix[i];
        }
    }

    /**
     * @brief 差分
     * <p>
     * 差分数组的运用场景为频繁区间修改操作。
     * 比如输入一个数组 nums，然后又要求给区间 nums[2..6] 全部加 1，
     * 再给 nums[3..9] 全部减 3，再给 nums[0..4] 全部加 2，再给…
     * 一通操作猛如虎，然后问你，最后 nums 数组的值是什么？
     * <p>
     * 这时用到了差分数组，可以把每一次操作的结果都记录下来，
     * 然后每次操作的时候，只需要把操作的结果加到差分数组中即可。
     * 最后根据差分数组的前缀和反推出原数组即可。
     * <p>
     * e.g.
     */
    class Difference {
        // 差分数组
        private int[] diff;

        /* 输入一个初始数组，区间操作将在这个数组上进行 */
        public Difference(int[] nums) {
            diff = new int[nums.length];
            // 根据初始数组构造差分数组
            diff[0] = nums[0];
            for (int i = 1; i < nums.length; i++) {
                diff[i] = nums[i] - nums[i - 1];
            }
        }

        /* 给闭区间 [i, j] 增加 val（可以是负数）*/
        public void increment(int i, int j, int val) {
            diff[i] += val;
            if (j + 1 < diff.length) {
                diff[j + 1] -= val;
            }
        }

        /* 返回结果数组 */
        public int[] result() {
            int[] res = new int[diff.length];
            // 根据差分数组构造结果数组
            res[0] = diff[0];
            for (int i = 1; i < diff.length; i++) {
                res[i] = res[i - 1] + diff[i];
            }
            return res;
        }
    }


    ///region 树上差分
    /**
     * 树上差分可以理解为对树上的某一段路径进行差分操作，这里的路径可以类比一维数组的区间进行理解。
     * 例如在对树上的一些路径进行频繁操作，并且询问某条边或者某个点在经过操作后的值的时候，就可以运用树上差分思想了。
     */

    /**
     * @brief 点差分
     */


    /**
     * @brief 边差分
     */
    //endregion


}



