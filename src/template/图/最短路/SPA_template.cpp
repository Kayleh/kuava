#include <bits/stdc++.h>
using namespace std;

// Q: 给你一个带正权的无向连通图，求最多经过k个点的最短路的权值和
// 1。bellman-ford
int bellmanFord(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    const int INF = 0x3f3f3f3f;
    // bellman-ford 解法思路：
    vector<int> dis(n, INF); // dis[i] 表示从src（起点）到i的最短距离
    dis[src] = 0;            // 起点到起点的距离为0
    for (int i = 0; i <= k; i++)
    {
        vector<int> temp(dis); // 临时数组，用于存储上一次迭代的结果
        for (auto &flight : flights)
        {
            int a = flight[0], b = flight[1], c = flight[2];
            temp[b] = min(temp[b], dis[a] + c); // 从a到b的距离，取上一次迭代的结果和本次迭代的结果的最小值
        }
        dis = temp;
    }
    return dis[dst] == INF ? -1 : dis[dst];
}

// 2.dfs
int dfs(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    const int INF = 0x3f3f3f3f;
    vector<vector<int>> g(n, vector<int>(n, INF)); // g[i][j] 表示i到j的距离
    for (auto &flight : flights)
    {
        int a = flight[0], b = flight[1], c = flight[2];
        g[a][b] = c;
    }
    vector<int> vis(n, 0); // vis[i] 表示i是否被访问过
    int ans = INF;
    function<void(int, int, int)> dfs = [&](int u, int d, int cost)
    {
        if (d > k + 1)
            return;
        if (u == dst)
        {
            ans = min(ans, cost);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (vis[i] || g[u][i] == INF)
                continue;
            vis[i] = 1;
            dfs(i, d + 1, cost + g[u][i]);
            vis[i] = 0;
        }
    };
    vis[src] = 1;
    dfs(src, 0, 0);
    return ans == INF ? -1 : ans;
}