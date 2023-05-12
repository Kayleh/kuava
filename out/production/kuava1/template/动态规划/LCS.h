using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();
        // dp表示 text1[0..i] 和 text2[0..j] 的最长公共子序列长度
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1]) // 如果两个字符相等
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1; // 那么最长公共子序列长度就是两个字符串都去掉最后一个字符的最长公共子序列长度加1
                }
                else
                {
                    // 如果两个字符不相等，那么最长公共子序列长度就是两个字符串去掉最后一个字符的最长公共子序列长度的最大值
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};