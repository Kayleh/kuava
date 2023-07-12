//
// Created by w1z4Rd on 23/07/10.
//

using namespace std;

#include <bits/stdc++.h>

/**
给你一个下标从 0 开始的整数数组 nums ，表示一些石块的初始位置。再给你两个长度 相等 下标从 0 开始的整数数组 moveFrom 和 moveTo 。

在 moveFrom.length 次操作内，你可以改变石块的位置。在第 i 次操作中，你将位置在 moveFrom[i] 的所有石块移到位置 moveTo[i] 。

完成这些操作后，请你按升序返回所有 有 石块的位置。

注意：

如果一个位置至少有一个石块，我们称这个位置 有 石块。
一个位置可能会有多个石块。
*/
struct Node {
    int to, next;
} edge[100005];

int head[100005], cnt;

void add(int u, int v) {
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void init(int n) {
    cnt = 0;
    for (int i = 0; i <= n; i++)
        head[i] = -1;
}

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        // 返回能够形成的最小高度树的根节点
        vector<int> ans;
        if (n == 1) {
            ans.push_back(0);
            return ans;
        }
        init(n);
        vector<int> degree(n, 0);
        for (auto &e: edges) {
            add(e[0], e[1]);
            add(e[1], e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                q.push(i);
        }
        // 拓扑排序的最后一层就是最小高度树的根节点
        while (!q.empty()) {
            ans.clear(); // 清空
            int size = q.size(); // 当前层的节点数
            for (int i = 0; i < size; i++) {
                int u = q.front();
                q.pop();
                ans.push_back(u);
                for (int j = head[u]; ~j; j = edge[j].next) {
                    int v = edge[j].to;
                    degree[v]--;
                    if (degree[v] == 1)
                        q.push(v);
                }
            }
        }
        return ans;
    }
};
