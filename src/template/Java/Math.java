package template.Java;

public class Math {
    // 最大公约数
    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // 最小公倍数
    public static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }


    // 扩展欧几里得算法
    // ax + by = gcd(a, b)
    // 返回值为gcd(a, b)
    public static int exgcd(int a, int b, int[] x, int[] y) {
        if (b == 0) {
            x[0] = 1;
            y[0] = 0;
            return a;
        }
        int r = exgcd(b, a % b, y, x);
        y[0] -= a / b * x[0];
        return r;
    }
}
