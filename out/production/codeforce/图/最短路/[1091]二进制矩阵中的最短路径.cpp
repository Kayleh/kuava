//给你一个 n x n 的二进制矩阵 grid 中，返回矩阵中最短 畅通路径 的长度。如果不存在这样的路径，返回 -1 。 
//
// 二进制矩阵中的 畅通路径 是一条从 左上角 单元格（即，(0, 0)）到 右下角 单元格（即，(n - 1, n - 1)）的路径，该路径同时满足下述要求
//： 
//
// 
// 路径途经的所有单元格都的值都是 0 。 
// 路径中所有相邻的单元格应当在 8 个方向之一 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。 
// 
//
// 畅通路径的长度 是该路径途经的单元格总数。 
//
// 
//
// 示例 1： 
// 
// 
//输入：grid = [[0,1],[1,0]]
//输出：2
// 
//
// 示例 2： 
// 
// 
//输入：grid = [[0,0,0],[1,1,0],[1,1,0]]
//输出：4
// 
//
// 示例 3： 
//
// 
//输入：grid = [[1,0,0],[1,1,0],[1,1,0]]
//输出：-1
// 
//
// 
//
// 提示： 
//
// 
// n == grid.length 
// n == grid[i].length 
// 1 <= n <= 100 
// grid[i][j] 为 0 或 1 
// 
//
// Related Topics 广度优先搜索 数组 矩阵 👍 229 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int shortestPathBinaryMatrix(vector <vector<int>> &grid) {
        // 八个方向
        int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        queue <pair<int, int>> q;
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;// 起点或终点为1,无法到达
        if (n == 1) return 1;// 只有一个点
        q.push({0, 0});// 起点入队
        grid[0][0] = 1;// 标记已访问
        int step = 1;// 起点到起点的距离为1
        while (!q.empty()) { // BFS
            int size = q.size();  // 当前层的节点数
            while (size--) {    // 遍历当前层的节点
                auto[x, y] = q.front(); // 取出队首元素
                q.pop();
                for (int i = 0; i < 8; i++) { // 遍历八个方向
                    int nx = x + dx[i]; 
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 1) continue; // 越界或已访问
                    if (nx == n - 1 && ny == n - 1) return step + 1; // 到达终点
                    q.push({nx, ny}); // 入队
                    grid[nx][ny] = 1; // 标记已访问
                }
            }
            step++;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
