//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 1961 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        // bfs
        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int ans = 0;

        rep(i,0,m-1){
            rep(j,0,n-1){
                if(grid[i][j] == '1'){
                    ans++;
                    q.push({i,j});// 将当前位置入队
                    grid[i][j] = '0'; // 将当前位置标记为已访问
                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();
                        forin(d,dir){
                            int nx = x + d[0];
                            int ny = y + d[1];
                            if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '0') continue;
                            q.push({nx,ny});// 将当前位置入队
                            grid[nx][ny] = '0';// 将当前位置标记为已访问
                        }
                    }
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
