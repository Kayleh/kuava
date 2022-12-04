import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public int minScore(int n, int[][] roads) {
        // 建图
        List[] e = new ArrayList[n + 1];    // 邻接表
        List[] v = new ArrayList[n + 1];    // 邻接表
        for (int i = 1; i <= n; i++) {
            e[i] = new ArrayList<Integer>();
            v[i] = new ArrayList<Integer>();
        }
        for (int[] road : roads) {
            e[road[0]].add(road[1]);
            v[road[0]].add(road[2]);
            e[road[1]].add(road[0]);
            v[road[1]].add(road[2]);
        }

        int ans = Integer.MAX_VALUE;

        //bfs
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(1);
        boolean[] visited = new boolean[n + 1];
        while (!queue.isEmpty()) {
            Integer sn = queue.poll(); // 枚举sn的所有边
            for (int i = 0; i < e[sn].size(); i++) {
                ans = Math.min(ans, (int) v[sn].get(i));
                int en = (int) e[sn].get(i);
                if (visited[en]) continue;
                visited[en] = true;
                queue.offer(en);
            }
        }
        return ans;
    }
}