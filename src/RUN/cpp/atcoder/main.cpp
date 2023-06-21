using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define fio                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);

int main()
{
    int N; // 初始序列长度 都为0
    int K; // 最大的k个数
    int Q; // 操作次数
    std::cin >> N >> K >> Q;

    // X , Y
    // 表示把第X-1个数变成Y，然后实时的求最大的K个数的和

    std::vector<int> sequence(N, 0); // 存储原始数字序列
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // 小顶堆，优先队列大小为k
    int maxSum = 0;
    pq.push(0); // 初始化堆，插入一个0作为初始元素

    while (Q--)
    {
        int x, y;
        std::cin >> x >> y;
       
    }

    return 0;
}