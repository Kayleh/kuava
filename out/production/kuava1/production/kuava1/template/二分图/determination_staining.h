#include <bits/stdc++.h>

using namespace std;

/**
 * 二分图是指能将所有点分成两个集合，使得每条边的两个端点分别在两个集合中
 *
 * 染色法：给图中的每个点染色，使得相邻的点颜色不同，如果能够染色成功，则是二分图
 * 做法：从一个点开始，将其染色为1，然后将其相邻的点染色为-1，然后将相邻的点的相邻的点染色为1，以此类推
 */
class determination_staining
{
public:
    /**
     * 判断是否是二分图
     * @param edges 边集数组
     */
    bool is_bipartite_graph(vector<vector<int>> &edges)
    {
        int n = edges.size(); // 点的数量
        vector<int> color(n); // 每个点的颜色，0表示未染色，1表示染色为1，-1表示染色为-1
        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0 && !dfs(edges, color, i, 1))
            {
                return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>> &edges, vector<int> &color, int cur, int c)
    {
        if (color[cur] != 0) // 已经染色
        {
            return color[cur] == c; // 判断是否染色正确
        }
        color[cur] = c;                             // 染色
        for (int i = 0; i < edges[cur].size(); i++) // 遍历相邻的点
        {
            if (!dfs(edges, color, edges[cur][i], -c)) // 染色相邻的点
            {
                return false;
            }
        }
        return true;
    }
};
