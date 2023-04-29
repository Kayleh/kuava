/*
 *  $ codeforce  2022-08-21
 *
 *  Copyright 2022  Kayleh. All rights reserved.
 *  @see {@link https://github.com/Kayleh/kuava}
 *
 */
package template.Java.图论;

public class 图的存储 {
    /**
     * @brief 直接存边
     * <p>
     * 使用一个数组来存边，数组中的每个元素edge都包含一条边的起点与终点（带边权的图还包含边权）。
     * （或者使用多个数组分别存起点，终点和边权。）
     */
    class side {
        int from[];// 边的起点
        int to[];// 边的终点
        int weight[];// 边的权重
        int size;// 边的数量

        /**
         * @brief 构造函数
         */
        public side(int n) {
            this.from = new int[n];
            this.to = new int[n];
            this.weight = new int[n];
            this.size = 0;
        }

        /**
         * @brief 添加一条边
         */
        public void add(int from, int to, int weight) {
            this.from[size] = from;
            this.to[size] = to;
            this.weight[size] = weight;
            this.size++;
        }

        public void dfs(int start, boolean[] visited) {
            if (visited[start]) return;
            visited[start] = true;
            for (int i = 0; i < this.size; i++) {
                if (this.from[i] == start) {
                    dfs(this.to[i], visited);
                }
            }
        }

        /**
         * @brief 遍历图
         */
        public void traverse() {
            //遍历的结果
            int result[] = new int[this.size];
            //记录访问过的点
            boolean[] visited = new boolean[this.size];
            for (int i = 0; i < this.size; i++) {
                if (!visited[i]) {
                    dfs(i, visited);
                }
            }
        }


    }
}
