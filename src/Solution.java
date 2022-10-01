import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int n = isWater.length;
        int m = isWater[0].length;
        int[][] ans = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = -1;
            }
        }
        // bfs
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0; // 从水开始 bfs
                    q.add(new int[]{i, j});
                }
            }
        }
        int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int x = cur[0] + dir[i][0];
                int y = cur[1] + dir[i][1];
                if (x >= 0 && x < n && y >= 0 && y < m && ans[x][y] == -1) {
                    ans[x][y] = ans[cur[0]][cur[1]] + 1;
                    q.add(new int[]{x, y});
                }
            }
        }
        return ans;
    }
}