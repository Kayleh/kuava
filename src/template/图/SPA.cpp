#include <bits/stdc++.h>

using namespace std;

// Q:图的最短路算法中，结果的最大值表示什么意思？
// A:表示从起点到终点的最短距离，如果最大值为INF，则表示起点到终点不可达

// 最短路SPA
/**
 * 1. floyd 临接矩阵
 *
 * 从任意起点出发，到达任意起点的最短距离
 *
 */
void floyd()
{
    int n, m; // n表示点数，m表示边数
    cin >> n >> m;
    int g[n][n];                // g[i][j]表示i到j的边的权值
    memset(g, 0x3f, sizeof(g)); // 默认为无穷大
    for (int i = 0; i < m; i++)
    {
        int u, v, w; // u,v,w分别表示边的起点，终点，权值
        cin >> u >> v >> w;
        g[u][v] = w;
    }
    for (int k = 0; k < n; k++)                            // 枚举中转点（表示从i经过k到j）
        for (int i = 0; i < n; i++)                        // 枚举起点
            for (int j = 0; j < n; j++)                    // 枚举终点
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]); // 松弛操作（取最小值）比较i到j的距离和i经过k到j的距离哪个更近
    //  输出
    for (int i = 0; i < n; i++)     // 枚举起点
        for (int j = 0; j < n; j++) // 枚举终点
            cout << "从" << i << "到" << j << "的最短距离为：" << g[i][j] << endl;
}

/**
 * 2.朴素 Dijkstra 邻接矩阵
 * ⌈非负权图 上单源最短路径⌉
 *
 * 从单个起点出发，到达任意起点的最短距离
 */
void dijkstra()
{
    int n, m; // n表示点数，m表示边数
    cin >> n >> m;
    int g[n][n]; // g[i][j]表示i到j的边的权值
    int dist[n]; // dist[i]表示从起点到i的最短距离为dist[i]
    bool vis[n]; // vis[i]表示i是否已经访问过
    int INF = 0x3f3f3f3f;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = i == j ? 0 : INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w; // u,v,w分别表示边的起点，终点，权值
        cin >> u >> v >> w;
        g[u][v] = w;
    }

    // dijkstra
    memset(dist, 0x3f, sizeof(dist)); // 初始化dist数组为无穷大
    memset(vis, false, sizeof(vis));  // 初始化vis数组为false

    for (int i = 0; i < n; i++)
    {
        // 迭代n次，每次找到「最短距离最小」且「未被更新」的点 t
        int t = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && (t == -1 || dist[j] < dist[t])) // 如果j未被更新且j的最短距离小于t的最短距离
                t = j;
        }
        vis[t] = true; // 标记t已经被更新
        for (int j = 0; j < n; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]); // 松弛操作（取最小值）比较j的最短距离和t的最短距离加上t到j的距离哪个更近
        }
    }

    // 输出
    for (int i = 0; i < n; i++)
    {
        cout << "从" << 0 << "到" << i << "的最短距离为：" << dist[i] << endl;
    }
}

/**
 * 3.堆优化 Dijkstra 邻接表
 */
void dijkstra_heap()
{
    int n, m; // n表示点数，m表示边数
    cin >> n >> m;
    vector<pair<int, int>> g[n]; // g[i][j]表示i到j的边的权值
    int dist[n];                 // dist[i]表示从起点到i的最短距离为dist[i]
    bool vis[n];                 // vis[i]表示i是否已经访问过
    int INF = 0x3f3f3f3f;

    for (int i = 0; i < m; i++)
    {
        int u, v, w; // u,v,w分别表示边的起点，终点，权值
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    // dijkstra
    memset(dist, 0x3f, sizeof(dist)); // 初始化dist数组为无穷大
    memset(vis, false, sizeof(vis));  // 初始化vis数组为false

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap; // 小根堆： 第一个参数表示距离，第二个参数表示点
    heap.push({0, 0});                                                                    // 起点为0，距离为0
    dist[0] = 0;                                                                          // 起点到起点的距离为0

    while (!heap.empty())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (vis[ver])
            continue;
        vis[ver] = true;
        for (auto &e : g[ver])
        {
            int next = e.first, d = e.second;
            if (dist[next] > dist[ver] + d)
            {
                dist[next] = dist[ver] + d;
                heap.push({dist[next], next});
            }
        }
    }

    // 输出
    for (int i = 0; i < n; i++)
    {
        cout << "从" << 0 << "到" << i << "的最短距离为：" << dist[i] << endl;
    }
}
