// 总共能够采药的时间为T，有M株草药，每株草药采摘用时ti，价值vi。
//在规定的时间内可以采到的草药的最大总价值。


#include <bits/stdc++.h>

using namespace std;
const int N = 105;
int CNT, TIME, ans;

struct Node {
    int t, v;  // t 代表时间，b 代表价值
    double f;  // f为性价比
} node[N];

bool operator<(Node p, Node q) { return p.f > q.f; }

/**
 * 计算在当前时间下，剩余物品的最大价值
 * 估价函数 f，可以剪掉所有无效的 0 枝条（就是剪去大量无用不选枝条）。
 * @param index     当前考虑的草药编号
 * @param ttime   剩余时间
 * @return
 */
int f(int index, int ttime) {
    int tot = 0; // 总价值
    for (int i = 1; index + i <= CNT; i++) // 遍历剩余的草药
        if (ttime >= node[index + i].t) { // 如果剩余时间足够采摘当前草药
            ttime -= node[index + i].t; // 更新剩余时间
            tot += node[index + i].v; // 更新总价值
        } else {
            return (int) (tot + ttime * node[index + i].f); // 否则返回剩余时间内采摘的总价值
        }
    return tot;
}

/**
 * 在给定时间内选择草药并计算最大总价值
 * @param index 当前考虑的草药编号
 * @param totime 剩余时间
 * @param v 当前的总价值
 */
void dfs(int index, int totime, int v) {
    ans = max(ans, v);
    if (index > CNT) {
        // 边界条件：只有n种物品
        return;
    }
    /*
     * 如果当前草药可以在剩余时间内采摘完成且不超出最大总价值，则继续递归考虑下一个草药；否则在剩余时间内采摘当前草药并更新总价值。
     */
    if (f(index, totime) + v > ans) {
        // 最优性剪枝(在不取的时候判断一下不取这个时，剩下的药所有的价值 + 现有的价值是否大于目前找到的最优解)
        dfs(index + 1, totime, v);
    }
    if (node[index].t <= totime) {
        // 可行性剪枝(取的时候判断一下是不是超过了规定时间)
        dfs(index + 1, totime - node[index].t, v + node[index].v);
    }
}

int main() {
    scanf("%d %d", &TIME, &CNT);
    for (int i = 1; i <= CNT; i++) {
        scanf("%d %d", &node[i].t, &node[i].v);
        node[i].f = 1.0 * node[i].v / node[i].t;
    }
    sort(node + 1, node + CNT + 1);  // 根据性价比排序
    dfs(1, TIME, 0);
    printf("%d\n", ans);
    return 0;
}
