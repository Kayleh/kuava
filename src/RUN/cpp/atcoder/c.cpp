#include <bits/stdc++.h>

using namespace std;

/**
 * 您的计算机的键盘具有三个键：“a”键、Shift 键和 Caps Lock 键。Caps Lock 键上有一盏灯。最初，Caps Lock 键上的灯熄灭，屏幕显示空字符串。
 * 您可以按任意顺序任意次数地执行以下三个操作：
 *
 * 花费X仅按下“a”键的毫秒数。如果 Caps Lock 键上的灯熄灭，a则会附加到屏幕上的字符串；如果它打开则为A。
 * 花费Y同时按下“a”键和 Shift 键的毫秒数。如果 Caps Lock 键上的灯熄灭，A则会附加到屏幕上的字符串；如果它打开，则为a。
 * 花费Z为按下 Caps Lock 键的毫秒数。如果 Caps Lock 键上的灯熄灭，它就会亮起；如果它打开，它会关闭。
 *
 * 给定一个字符串S:
 * 由A和a组成，确定至少需要多少毫秒才能使屏幕上显示的字符串等于S.
 */
int minimumMilliseconds(string S, int X, int Y, int Z)
{
    int n = S.length();

    // 小写输入：1.（Caps Lock键灯关闭时按下a键的毫秒数）= X
    //          2.（Caps Lock键灯开启时按下Shift键和a键的毫秒数） = Y
    //          3.（Caps Lock键灯开启时按下Caps Lock键的毫秒 + a键的毫秒数） = Z + X

    // 大写输入：1.（Caps Lock键灯关闭时按下Shift键和a键的毫秒数） = Y
    //          2.（Caps Lock键灯开启时按下a键的毫秒数） = X
    //          3.（Caps Lock键灯开启时按下Caps Lock键的毫秒 + Shift键和a键的毫秒数） = Z + Y

    // 动态规划
    int dp[n + 1][3];        // dp[i][j] 表示输入第i个字符，  j = 0表示直接输入， j = 1表示大写输入， j = 2表示按下Caps Lock键
    dp[0][0] = dp[0][1] = 0; // 初始状态
    for (int i = 1; i <= n; i++)
    {
        // 小写输入
        dp[i][0] = min(dp[i - 1][0] + X, dp[i - 1][1] + Y); // 小写输入，最后一个字符为小写
        dp[i][1] = min(dp[i - 1][0] + Y, dp[i - 1][1] + X); // 小写输入，最后一个字符为大写

        // 大写输入
        if (S[i - 1] == 'A')
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + Z); // 大写输入，最后一个字符为小写
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + Z); // 大写输入，最后一个字符为大写
        }
    }

    return min(dp[n][0], dp[n][1]);
}

int main()
{
    string S;
    int X, Y, Z;

    cin >> X;
    cin >> Y;
    cin >> Z;
    cin >> S;

    int minMilliseconds = minimumMilliseconds(S, X, Y, Z);
    cout << minMilliseconds << endl;
    return 0;
}
