#include <bits/stdc++.h>

using i64 = long long;

/**
 * 从小到大排序, ranks[i] 为排名为 i 的元素在原序列中的下标
 */
void solve()
{
    std::vector<int> a = {2, 4, 1, 3, 5};
    std::vector<int> ranks(a.size());
    std::iota(ranks.begin(), ranks.end(), 0);
    std::sort(ranks.begin(), ranks.end(), [&](int i, int j)
              { return a[i] < a[j]; });
    for (auto i : ranks)
        std::cout << i << " ";
}

/**
 * 逆序
 */
void solve2()
{
    std::vector<int> a = {2, 4, 1, 3, 5};
    std::vector b(a.rbegin(), a.rend());
    for (auto i : b)
        std::cout << i << " ";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve2();
    return 0;
}