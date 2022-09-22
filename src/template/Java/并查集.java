package template.Java;

public class 并查集 {
}

class 并查集Solution {
    /**
     * 如果我们有 k 对情侣形成了错误环，需要交换 k - 1 次才能让情侣牵手。
     * 问题转化成 n / 2 对情侣中，有多少个这样的环。
     *
     * @param row
     * @return
     */
    int[] p = new int[60]; // 连通块的父节点

    public int minSwapsCouples(int[] row) {
        int len = row.length;
        int cnt = len / 2; //情侣对数
        for (int i = 0; i < cnt; i++) {
            p[i] = i;// 初始化，每个节点的父节点是自己
        }
        for (int i = 0; i < len; i += 2) {
            union(row[i] / 2, row[i + 1] / 2); // 将相邻的两个人所在的连通块合并
        }
        int count = 0;
        for (int i = 0; i < cnt; i++) {
            if (find(i) == i) {
                count++;
            }
        }
        return cnt - count;
    }

    /**
     * 合并连通块
     *
     * @param i
     * @param i1
     */
    private void union(int i, int i1) {
        p[find(i)] = find(i1);// 将 i 和 i1 所在的连通块合并
    }

    /**
     * 查找 i 所在的连通块的根节点
     *
     * @param i
     * @return
     */
    private int find(int i) {
        if (p[i] != i) {
            p[i] = find(p[i]);
        }
        return p[i];
    }
}