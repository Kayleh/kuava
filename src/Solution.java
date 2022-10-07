import java.util.Arrays;

class Solution {
    public int Leetcode(String[] words) {
        String target = "helloleetcode";

        //
        // 可以从一个单词中多次取字母，每个字母仅可被取一次
        // 从多个单词中取字母，使得取得的字符串为 helloleetcode
        // 返回取得字符串 helloleetcode 的最小代价

        //动态规划
        // dp[i][j]表示从第i个单词中取字母，取得字符串为need.substring(0,j)的最小代价
        // dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + cost[i][j])

        int n = words.length;
        int m = target.length();
        int[][] dp = new int[n + 1][m + 1];

        //初始化
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }

        //计算dp
        //从一个单词中取一个字母所需要的代价，为该字母左边和右边字母数量之积, 取完后，该字母不再可用



        //从一个单词中取一个字母所需要的代价，为该字母左边和右边字母数量之积
        System.out.println(Arrays.deepToString(dp));

        return dp[n - 1][m - 1];

    }

    private int cost(String word, String substring) {


        if (word.contains(substring)) {
            int index = word.indexOf(substring);
            int left = index;
            int right = word.length() - index - 1;
            return left * right;
        } else {
            return Integer.MAX_VALUE;
        }
    }


    int getCost(String s, int index) {
        return index * (s.length() - index - 1);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        //words = ["hold","engineer","cost","level"]
        String[] words = {"hold", "engineer", "cost", "level"};
        System.out.println(solution.Leetcode(words));
    }
}