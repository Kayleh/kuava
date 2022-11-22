class Solution {
    int mod = 1000000007;
    boolean[][] flag;
    int n;
    boolean[] isPrime = {false, false, true, true, false, true, false, true, false, false};

    //给你一个字符串 s ，每个字符是数字 '1' 到 '9' ，再给你两个整数 k 和 minLength 。
    //
    //如果对 s 的分割满足以下条件，那么我们认为它是一个 完美 分割：
    //
    //s 被分成 k 段互不相交的子字符串。
    //每个子字符串长度都 至少 为 minLength 。
    //每个子字符串的第一个字符都是一个 质数 数字，最后一个字符都是一个 非质数 数字。质数数字为 '2' ，'3' ，'5' 和 '7' ，剩下的都是非质数数字。
    //请你返回 s 的 完美 分割数目。由于答案可能很大，请返回答案对 109 + 7 取余 后的结果。
    //一个 子字符串 是字符串中一段连续字符串序列。
    public int beautifulPartitions(String s, int k, int minLength) {
        //思路：动态规划
        n = s.length();
        //每个子字符串的第一个字符都是一个 质数 数字，最后一个字符都是一个 非质数 数字。质数数字为 '2' ，'3' ，'5' 和 '7' ，剩下的都是非质数数字。
        char[] chars = s.toCharArray();
        //预处理 用于判断一个字符是否满足条件
        flag = new boolean[n][n]; //flag[i][j]表示s的第i个字符到第j个字符是否满足条件
        boolean[] yes = new boolean[n]; //用于判断一个字符是否是质数
        for (int i = 0; i < n; i++) {
            yes[i] = isPrime[chars[i] - '0'];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (j - i + 1 < minLength) {
                    continue;
                }
                if (yes[i] && !yes[j]) {
                    flag[i][j] = true;
                }
            }
        }

        int[][] dp = new int[n][k + 1]; //dp[i][j]表示s的前i个字符分成j段的完美分割数目
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                if (j == 1) {
                    if (flag[0][i]) {
                        dp[i][j] = 1;
                    }
                } else {
                    for (int l = 0; l < i; l++) {
                        if (flag[l + 1][i]) {
                            dp[i][j] = (dp[i][j] + dp[l][j - 1]) % mod;
                        }
                    }
                }
            }
        }
        return dp[n - 1][k];
    }

    private boolean yes(int i, int j, String s) {
        char c = s.charAt(i);
        switch (c) {
            case '2':
            case '3':
            case '5':
            case '7':
                c = s.charAt(j);
                switch (c) {
                    case '1':
                    case '4':
                    case '6':
                    case '8':
                    case '9':
                        return true;
                    default:
                        return false;
                }
        }
        return false;
    }

}