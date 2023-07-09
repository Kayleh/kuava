//
// Created by w1z4Rd on 2022/10/27.
//

// #ifndef KUAVA_UNIONFIND_H
// #define KUAVA_UNIONFIND_H
//
// #endif //KUAVA_UNIONFIND_H

/**
 * 并查集
 * 可撤销的并查集
 */
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

const int MAXN = 1e5 + 5; // 顶点数

class DsuFind_Rollback // 可撤销的并查集
{
private:
    vector<int> parent; // 记录父节点 parent[i] = j 表示 i 的父节点是 j
    vector<int> rank;   // 记录树的高度 rank[i] 表示以 i 为根的集合所表示的树的层数
    int count;          // 连通分量的个数
    // vector<int> nodes;  // 记录每个连通分量的节点数
    // vector<int> edges;  // 记录每个连通分量的边数
    stack<pair<int, int>> stk; // 记录每次操作的节点和父节点

    void rollback() {
        if (stk.empty())
            return;
        auto [x, y] = stk.top();
        stk.pop();
        parent[x] = y;
        count++;
    }

    int find(int p) {
        if (p != parent[p])
            parent[p] = find(parent[p]); // 路径压缩: 将路径上的每个节点都指向根节点, 从而缩短查询路径, 优化查询性能
        return parent[p];
    }

    void connect(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;

        if (rank[rootP] < rank[rootQ]) { // 让 rank 大的作为父节点
            swap(rootP, rootQ);
        }
        stk.push({rootQ, parent[rootQ]});
        parent[rootQ] = rootP;
        count--;
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; // 顶点数
    cin >> N;

    int opr;
    cin >> opr;

    DsuFind uf(N);
    while (opr-- > 0) {
        int type;
        cin >> type;
        if (type == 1) // union (x,y)
        {
            int x, y;
            cin >> x >> y;
            uf.connect(x, y);
        } else if (type == 2) //  is connect ( x, y)
        {
            int x, y;
            cin >> x >> y;

            if (uf.isConnected(x, y))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
    }
    return 0;
}
