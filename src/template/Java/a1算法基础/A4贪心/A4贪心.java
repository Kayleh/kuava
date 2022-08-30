/*
 *  $ codeforce  2022-08-28
 *
 *  Copyright 2022  Kayleh. All rights reserved.
 *  @see {@link https://github.com/Kayleh/kuava}
 *
 */

package template.Java.a1算法基础.A4贪心;

/**
 * @brief 贪心算法
 * 贪心算法（英语：greedy algorithm），
 * 是用计算机来模拟一个「贪心」的人做出决策的过程。
 * 这个人十分贪婪，每一步行动总是按某种指标选取最优的操作。
 * 而且他目光短浅，总是只看眼前，并不考虑以后可能造成的影响。
 * <p>
 * 可想而知，并不是所有的时候贪心法都能获得最优解，所以一般使用贪心法的时候，都要确保自己能证明其正确性。
 */
public class A4贪心 {


    /*
      在提高组难度以下的题目中，最常见的贪心有两种。

     1 「我们将 XXX 按照某某顺序排序，然后按某种顺序（例如从小到大）选择。」。
     2 「我们每次都取 XXX 中最大/小的东西，并更新 XXX。」（有时「XXX 中最大/小的东西」可以优化，比如用优先队列维护）
      二者的区别在于一种是离线的，先处理后选择；一种是在线的，边处理边选择。

      - 排序解法
        用排序法常见的情况是输入一个包含几个（一般一到两个）权值的数组，通过排序然后遍历模拟计算的方法求出最优值。

      - 后悔解法
        思路是无论当前的选项是否最优都接受，然后进行比较，如果选择之后不是最优了，则反悔，舍弃掉这个选项；否则，正式接受。如此往复。

        与动态规划的区别
        贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择，不能回退。
        动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能。

     */

    /*
        e.g.
        邻项交换法的例题
        NOIP 2012 国王游戏
        恰逢 H 国国庆，国王邀请 n 位大臣来玩一个有奖游戏。
        首先，他让每个大臣在左、右手上面分别写下一个整数，国王自己也在左、右手上各写一个整数。
        然后，让这 n 位大臣排成一排，国王站在队伍的最前面。排好队后，所有的大臣都会获得国王奖赏的若干金币，每位大臣获得的金币数分别是：
        排在该大臣前面的所有人的左手上的数的乘积除以他自己右手上的数，然后向下取整得到的结果。

        国王不希望某一个大臣获得特别多的奖赏，所以他想请你帮他重新安排一下队伍的顺序，使得获得奖赏最多的大臣，所获奖赏尽可能的少。
        注意，国王的位置始终在队伍的最前面。
     */

    /**
     * e.g.
     * 例题
     *
     *
     */




}
