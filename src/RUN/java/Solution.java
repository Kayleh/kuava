/**
 给你一个正整数 n ，请你返回 n 的 惩罚数 。

 n 的 惩罚数 定义为所有满足以下条件 i 的数的平方和：

 1 <= i <= n
 i * i 的十进制表示的字符串可以分割成若干连续子字符串，且这些子字符串对应的整数值之和等于 i 。
 */
class Solution {
    public int punishmentNumber(int n) {
        // 思路：dp[i] 表示 i 是否是惩罚数

        int[] dp = new int[n + 1];
        dp[0] = 1;
        int[] sum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + i * i;
            for (int j = 1; j <= i; j++) {
                if (sum[i] - sum[j - 1] > i) {
                    break;
                }
                if (dp[j - 1] == 1 && sum[i] - sum[j - 1] == i) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
}