//
// Created by w1z4Rd on 2022/10/27.
//

// #ifndef KUAVA_UNIONFIND_H
// #define KUAVA_UNIONFIND_H
//
// #endif //KUAVA_UNIONFIND_H

/**
 * 并查集
 * 用于解决图论中的动态连通性问题
 * 1. 判断两个节点是否连通
 * 2. 连接两个节点
 * 3. 统计连通分量的个数
 *
 *
 * 并查集的思路是将一组独立的元素集合合并成一个集合，同时记录每个集合的根节点。在并查集中，每个节点都有一个唯一的标识符，可以用来表示该节点所在的集合。当需要查询两个元素是否在同一个集合中时，可以通过并查集的查询操
 * 作来实现。
 * 
 * 路径压缩：
 * 路径压缩的思路是在查询过程中，将路径上的每个节点都指向根节点，从而缩短查询路径。具体来说，当一个节点被查询时，它的父节点会被更新为根节点。这样，当再次查询该节点时，可以直接从根节点开始查询，避免了在查找过程中
 * 出现的节点的多层嵌套问题，从而优化查询性能。
 * 总之，并查集和路径压缩都是为了优化树的查询性能而设计的。并查集可以快速地合并和查询集合，而路径压缩则可以减少查询过程中的路径长度，从而提高查询效率。
 *
 * 按秩合并：
 * 按秩合并的思路是在合并两个集合时，将高度小的树合并到高度大的树上。这样可以避免出现树的高度过大的情况（树的左右子树高度差过大），从而优化查询性能。
 */
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

const int MAXN = 1e5 + 5; // 顶点数

class DsuFind // 并查集
{
private:
    vector<int> parent; // 记录父节点 parent[i] = j 表示 i 的父节点是 j
    vector<int> rank;   // 记录树的高度 rank[i] 表示以 i 为根的集合所表示的树的层数
    int count;          // 连通分量的个数

public:
    DsuFind(int n)
    {
        count = n;
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int p)
    {
        while (p != parent[p])
        {
            parent[p] = parent[parent[p]]; // 路径压缩：将当前节点的父节点指向父节点的父节点
            p = parent[p];
        }
        return p;
    }

    // 不使用路径压缩
    int find2(int p)
    {
        if (p != parent[p])
            p = find(parent[p]);
        return p;
    }

    void connect(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        if (rank[rootP] > rank[rootQ]) // 按秩合并：将高度小的树合并到高度大的树上
        {
            parent[rootQ] = rootP;
            rank[rootP] += rank[rootQ];
        }
        else
        {
            parent[rootP] = rootQ;
            rank[rootQ] += rank[rootP];
        }
        count--;
    }

    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }

    int getCount()
    {
        return count; // 返回连通分量的个数
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; // 顶点数
    cin >> N;

    int opr;
    cin >> opr;

    DsuFind uf(N);
    while (opr-- > 0)
    {
        int type;
        cin >> type;
        if (type == 1) // union (x,y)
        {
            int x, y;
            cin >> x >> y;
            uf.connect(x, y);
        }
        else if (type == 2) //  is connect ( x, y)
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
