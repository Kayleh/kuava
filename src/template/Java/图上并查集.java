package template.Java;


public class 图上并查集 {

}
/**
 * 并查集
 * <p>
 * 基于rank的优化
 */

/**
 * 并查集
 * <p>
 * 基于rank的优化
 */
class UnionFind {
    public int count; // 连通分量数
    public int[] parent; // parent[i]表示第i个元素所指向的父节点
    public int[] rank; // rank[i]表示以i为根的集合所表示的树的层数

    public UnionFind(int[][] grid) {
        count = 0;
        parent = new int[grid.length * grid[0].length];
        rank = new int[grid.length * grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (i != 0 && i != grid.length - 1 && j != grid[0].length - 1 && j != 0 && grid[i][j] == 0) {
                    parent[i * grid[0].length + j] = i * grid[0].length + j;
                    count++;
                }
                rank[i * grid[0].length + j] = 0;
            }
        }
    }

    public UnionFind() {
    }

    public int find(int i) {
        if (parent[i] == i) {
            return i;
        } else {
            parent[i] = find(parent[i]);
            return parent[i];
        }
    }

    public void union(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return;
        if (rank[pi] < rank[pj]) {// 将层数低的集合合并到层数高的集合上
            parent[pi] = pj;
        } else if (rank[pi] > rank[pj]) {
            parent[pj] = pi;
        } else {
            parent[pi] = pj;
            rank[pj] += 1;
        }
        count--;
    }

    public int getCount() {
        return count;
    }
}

