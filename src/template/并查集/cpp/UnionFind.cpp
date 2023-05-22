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
 */
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

const int MAXN = 10010; // 顶点数

// 记录父节点
int father[MAXN];
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
}

int find(int k)
{
    if (father[k] == k)
        return k;
    else
        return father[k] = find(father[k]);
}

void connect(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x != y)
        father[x] = y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; // 顶点数
    cin >> N;

    int opr;
    cin >> opr;

    init(MAXN);
    while (opr-- > 0)
    {
        int type;
        cin >> type;
        if (type == 1) // union (x,y)
        {
            int x, y;
            cin >> x >> y;
            connect(x, y);
        }
        else if (type == 2) //  is connect ( x, y)
        {
            int x, y;
            cin >> x >> y;

            if (find(x) == find(y))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
    }
    return 0;
}


// -----------------------------------------------------------------使用map实现------------------------------------------------------
unordered_map<int, int> mp; // 并查集， 初始连通分量为元素本身
int find(int num)
{
    return mp[num] == num ? num : mp[num] = find(mp[num]);
}

void connect(int a, int b)
{
    if (mp.count(a) == 0 || mp.count(b) == 0) 
        return;
    int fa = find(a), fb = find(b);
    if (fa != fb)
        mp[fa] = fb;
}