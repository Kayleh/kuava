#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;


// Q:图的最短路算法中，结果的最大值表示什么意思？
// A:表示从起点到终点的最短距离，如果最大值为INF，则表示起点到终点不可达

// 最短路SPA
/**
 * 1. floyd 临接矩阵 [多源多汇最短路径]
 *
 * 求任意两个结点之间的最短路的
 */
void floyd() {
    int n, m; // n表示点数，m表示边数
    cin >> n >> m;
    int g[n][n];                // g[i][j]表示i到j的边的权值
    memset(g, INF, sizeof(g)); // 默认为无穷大
    for (int i = 0; i < m; i++) {
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
 * 2.朴素 Dijkstra 邻接矩阵 [非负权图单源最短路径]
 *
 * 从单个起点出发，到达任意点的最短距离
 */
void dijkstra() {
    int n, m; // n表示点数，m表示边数
    cin >> n >> m;
    int g[n][n]; // g[i][j]表示i到j的边的权值
    int dist[n]; // dist[i]表示从起点到i的最短距离为dist[i]
    bool vis[n]; // vis[i]表示i是否已经访问过

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = i == j ? 0 : INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w; // u,v,w分别表示边的起点，终点，权值
        cin >> u >> v >> w;
        g[u][v] = w;
    }

    // dijkstra
    memset(dist, INF, sizeof(dist)); // 初始化dist数组为无穷大
    memset(vis, false, sizeof(vis));  // 初始化vis数组为false

    for (int i = 0; i < n; i++) {
        // 迭代n次，每次找到「最短距离最小」且「未被更新」的点 t
        int t = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && (t == -1 || dist[j] < dist[t])) // 如果j未被更新且j的最短距离小于t的最短距离
                t = j;
        }
        vis[t] = true; // 标记t已经被更新
        for (int j = 0; j < n; j++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]); // 松弛操作（取最小值）比较j的最短距离和t的最短距离加上t到j的距离哪个更近
        }
    }

    // 输出
    for (int i = 0; i < n; i++) {
        cout << "从" << 0 << "到" << i << "的最短距离为：" << dist[i] << endl;
    }
}

/**
 * 3.堆优化 Dijkstra 邻接表
 */
void dijkstra_heap() {
    int n, m; // n表示点数，m表示边数
    cin >> n >> m;
    vector <pair<int, int>> g[n]; // g[i][j]表示i到j的边的权值
    int dist[n];                 // dist[i]表示从起点到i的最短距离为dist[i]
    bool vis[n];                 // vis[i]表示i是否已经访问过

    for (int i = 0; i < m; i++) {
        int u, v, w; // u,v,w分别表示边的起点，终点，权值
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    // dijkstra
    memset(dist, INF, sizeof(dist)); // 初始化dist数组为无穷大
    memset(vis, false, sizeof(vis));  // 初始化vis数组为false

    // 优先队列，把距离最小的点放在队首
    // 第一个参数pair<int, int>表示点的编号和距离
    // 第二个参数vector<pair<int, int>>表示比较方式，距离小的优先级高
    // 第三个参数greater<pair<int, int>>表示使用greater作为比较方式，优先级高的在队首
    priority_queue < pair < int, int >, vector < pair < int, int >>, greater < pair < int, int>>> heap;
    // 起点为0，距离为0
    heap.push({0, 0});
    // 起点到起点的距离为0
    dist[0] = 0;

    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (vis[ver])
            continue;
        vis[ver] = true;
        for (auto &e: g[ver]) {
            int next = e.first, d = e.second;
            if (dist[next] > dist[ver] + d) {
                dist[next] = dist[ver] + d;
                heap.push({dist[next], next});
            }
        }
    }

    // 输出
    for (int i = 0; i < n; i++) {
        cout << "从" << 0 << "到" << i << "的最短距离为：" << dist[i] << endl;
    }
}

/**
 * Bellman-Ford
 * 不断尝试对图上每一条边进行松弛。我们每进行一轮循环，就对图上所有的边都尝试进行一次松弛操作，当一次循环中没有成功的松弛操作时，算法停止
 * @return
 */
bool bellmanFord() {
    int n, m; // n表示点数，m表示边数
    cin >> n >> m;
    int dist[n]; // dist[i]表示从起点到i的最短距离为dist[i]
    memset(dist, INF, sizeof(dist)); // 初始化dist数组为无穷大
    dist[0] = 0; // 起点到起点的距离为0

    // 松弛操作
    bool flag;
    for (int i = 0; i < n; i++) {
        flag = false;
        for (int j = 0; j < m; j++) {
            int u, v, w; // u,v,w分别表示边的起点，终点，权值
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                flag = true;
            }
        }
        if (!flag) break;
    }

    // 输出
    for (int i = 0; i < n; i++) {
        cout << "从" << 0 << "到" << i << "的最短距离为：" << dist[i] << endl;
    }
    // 第 n 轮循环仍然可以松弛时说明 s 点可以抵达一个负环
    return flag;
}

/**
 * 无权有向图的最短路（BFS）
 */
void bfs() {
    int n, m; // n表示点数，m表示边数
    cin >> n >> m;
    vector<int> g[n]; // g[i][j]表示i到j的边的权值
    int dist[n];      // dist[i]表示从起点到i的最短距离为dist[i]
    bool vis[n];      // vis[i]表示i是否已经访问过

    for (int i = 0; i < m; i++) {
        int u, v; // u,v分别表示边的起点，终点
        cin >> u >> v;
        g[u].push_back(v);
    }

    // bfs
    memset(dist, INF, sizeof(dist)); // 初始化dist数组为无穷大
    memset(vis, false, sizeof(vis));  // 初始化vis数组为false

    // 优先队列，把距离最小的点放在队首
    // 第一个参数pair<int, int>表示点的编号和距离
    // 第二个参数vector<pair<int, int>>表示比较方式，距离小的优先级高
    // 第三个参数greater<pair<int, int>>表示使用greater作为比较方式，优先级高的在队首
    queue<int> q;
    // 起点为0，距离为0
    q.push(0);
    // 起点到起点的距离为0
    dist[0] = 0;

    while (!q.empty()) {
        int t = q.front();
        q.pop();
        if (vis[t])
            continue;
        vis[t] = true;
        for (auto &e: g[t]) {
            if (dist[e] > dist[t] + 1) {
                dist[e] = dist[t] + 1;
                q.push(e);
            }
        }
    }

    // 输出
    for (int i = 0; i < n; i++) {
        cout << "从" << 0 << "到" << i << "的最短距离为：" << dist[i] << endl;
    }
}
