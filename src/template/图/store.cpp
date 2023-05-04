#include <bits/stdc++.h>

using namespace std;

// 图的存储

// 1. 邻接矩阵
// 适用于稠密图，即边数接近点数的平方
void adj_matrix()
{
    int n, m;
    cin >> n >> m;
    int g[n][n]; // g[i][j]表示i到j的边的权值
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; i++)
    {
        int u, v, w; // u,v,w分别表示边的起点，终点，权值
        cin >> u >> v >> w;
        g[u][v] = w;
    }
}

// 2. 邻接表
// 适用于稀疏图，即边数的数量接近点数
void adj_list()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n); // g[i]表示以i为起点的边的集合，pair<int,int>表示边的终点和权值
    for (int i = 0; i < m; i++)
    {
        int u, v, w; // u,v,w分别表示边的起点，终点，权值
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
}

// 3. 链式前向星
// 适用于稀疏图，即边数远小于点数的平方
/**
 * 链式前向星
 * @note 用于存储稀疏图，无向图需要存两个方向的边
 *
 *
 *
 *     head[]     edge[]: to, w, next
 *      ↓
 *    ┌───┬        to, next, w
 *    │ 0 │ ─────> 1,   2,   1 ─────> 2,3,-1
 *    └───┘
 *    ┌───┬
 *    │ 1 │ ─────> 2,   3,   2 ─────> 3,4,-1
 *    └───┘
 *     。。。
 *
 *
 */
const int maxn = 50; // 最大点数

struct node
{
    int to, next, w; // to表示指向的点，next表示下一个边，w表示边权
} edge[maxn * maxn]; // 边集数组，edges[i]表示编号为i的边

int head[maxn]; //  head[i]表示以i为起点的第一条边的下标（在edges数组中的下标）
int cnt, n, m;  // cnt表示边的数量，n表示点的数量，m表示边的数量

void init()
{
    memset(head, -1, sizeof(head)); // 初始化所有边的头结点为-1
    cnt = 0;
}

void add(int u, int v, int w)
{
    edge[cnt].to = v;         // 边的终点
    edge[cnt].w = w;          // 边的权值
    edge[cnt].next = head[u]; // 边的下一条边
    head[u] = cnt++;          //  更新边的头结点，即以u为起点的第一条边的下标
}

/**
 *  打印链式前向星
 */
void print()
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int j = head[i]; ~j; j = edge[j].next)
        {
            cout << "[" << edge[j].to << ", " << edge[j].w << "] ";
        }
        cout << endl;
    }
}

/**
 *  深度优先搜索
 *  @param u 起点
 */
void dfs(int u)
{
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v)
        {
            dfs(v);
        }
    }
}

/**
 *  广度优先搜索
 * @param u 起点
 */
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (v)
            {
                q.push(v);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    dfs(1);
    return 0;
}