import java.util.Arrays;

class Solution {
    int INF = 0x3f3f3f3f;

    public int minSteps(int n) {
        int[][] f = new int[n + 1][n + 1]; // f[i][j] 表示当前有 i 个 A，剪切板中有 j 个 A，最少需要多少步
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                f[i][j] = INF; // 初始化为一个很大的值
            }
        }
        f[1][0] = 0;// 1 个 A，剪切板中 0 个 A，不需要任何操作
        f[1][1] = 1;// 1 个 A，剪切板中 1 个 A，复制一次
        for (int i = 2; i <= n; i++) {
            int min = INF;// 记录 f[i][j] 的最小值
            for (int j = 0; j <= i / 2; j++) {//f[i][j] 的最后一次操作是由 Paste 而来，原来粘贴板的字符数不会超过 i / 2，
                f[i][j] = f[i - j][j] + 1; //最后一次操作是 Paste 操作：此时粘贴板的字符数量不会发生变化
                min = Math.min(min, f[i][j]); // 最后一次操作是 Copy All 操作：(i=j)那么此时的粘贴板的字符数与记事本上的字符数相等
            }
            f[i][i] = min + 1;
        }
        int ans = INF;
        for (int i = 0; i <= n; i++) ans = Math.min(ans, f[n][i]);
        for (int[] ints : f) {
            System.out.println(Arrays.toString(ints));
        }
        return ans;
    }

    public static void main(String[] args) {
        int mod = 1000000007;
        double mod2  = 1e9 + 7;
        System.out.println(mod);
        System.out.println((int)mod2);
    }
}