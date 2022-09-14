package template.Java.b搜索;

import java.util.Scanner;

/**
 * 基于已有的信息对搜索的每一个分支选择都做估价，进而选择分支。
 * 简单来说，启发式搜索就是对取和不取都做分析，从中选取更优解或删去无效解。
 */
public class 启发式搜索 {

    /**
     * @e.g. 有 N 种物品和一个容量为 W 的背包，每种物品有重量 Wi 和价值 Vi 两种属性，
     * 要求选若干个物品（每种物品只能选一次）放入背包，
     * 使背包中物品的总价值最大，且背包中物品的总重量不超过背包的容量。
     * <p>
     * <p>
     * 我们写一个估价函数 f ，可以剪掉所有无效的 0 枝条（就是剪去大量无用不选枝条）。
     * 估价函数 f 的运行过程如下：
     * 我们在取的时候判断一下是不是超过了规定体积（可行性剪枝）；
     * 在不取的时候判断一下不取这个时，剩下的药所有的价值 + 现有的价值是否大于目前找到的最优解（最优性剪枝）。
     */

    int n, m, ans;

    class Node {
        int a, b;  // a 代表时间，b 代表价值
        double f;
    }

    int N = 105;
    Node[] node = new Node[N];

    boolean operator(Node a, Node b) {
        return a.f > b.f;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt();
        int n = in.nextInt();
    }
}
