package template.Java;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * 拓扑排序
 */
public class TopoSort {
    /**
     * 判断有向图是否有环
     *
     * @param N    顶点数
     * @param edge 边
     * @return
     */
    public boolean canFinish(int N, int[][] edge) {
        int[] deg = new int[N];
        //region 邻接表
        List<Integer>[] G = new List[N];
        for (int i = 0; i < N; ++i) {
            G[i] = new ArrayList<>();
        }
        //endregion

        //region 根据edge构建邻接表 和 入度数组
        for (int[] p : edge) {
            G[p[1]].add(p[0]);
            deg[p[0]]++;
        }
        //endregion

        //region 将入度为0的节点入队
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < N; ++i) {
            if (deg[i] == 0) queue.offer(i);
        }
        //endregion

        //region 拓扑排序
        int cnt = 0;
        while (!queue.isEmpty()) {
            int u = queue.poll();
            cnt++;
            // 将u的邻接点的入度减一(相当于删了这个点)，如果入度为0，入队
            for (int v : G[u]) {
                if (--deg[v] == 0) {
                    queue.offer(v);
                }
            }
        }
        //endregion

        // 判断是否所有节点都被拓扑排序了
        return cnt == N;
    }
}
