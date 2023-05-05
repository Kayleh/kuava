#include <bits/stdc++.h>
using namespace std;

// Q: 给你一个带正权的无向连通图，求最多经过k个点的最短路
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