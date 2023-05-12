//
// Created by w1z4Rd on 2022/10/27.
//

//#ifndef KUAVA_UNIONFIND_H
//#define KUAVA_UNIONFIND_H
//
//#endif //KUAVA_UNIONFIND_H

/**
 * 并查集
 * 用于解决图论中的动态连通性问题
 * 1. 判断两个节点是否连通
 * 2. 连接两个节点
 * 3. 统计连通分量的个数
 */
#include <bits/stdc++.h>
class UnionFind {
public:
    int find(int x) {
        int root = x;

        while (father[root] != -1) {
            root = father[root];
        }

        while (x != root) {
            int original_father = father[x];
            father[x] = root;
            x = original_father;
        }

        return root;
    }

    bool is_connected(int x, int y) {
        return find(x) == find(y);
    }

    void merge(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x != root_y) {
            father[root_x] = root_y;
        }
    }

    void add(int x) {
        if (!father.count(x)) {
            father[x] = -1;
        }
    }

private:
    // 记录父节点
    unordered_map<int, int> father;
};

