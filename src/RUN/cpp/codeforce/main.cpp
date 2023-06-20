
using namespace std;
#include <bits/stdc++.h>

//@start——————————————————————————————————————————————————————————————————————

bool ok(int n, int m)
{
    if (n == m)
    {
        return true;
        return true;
    }
    else if (n % 3 != 0)
    {
        return false;
    }
    else
    {
        return (ok(n / 3, m) || ok(2 * n / 3, m)); // 递归，分别除以3和2/3
    }
}

void Solution()
{
    int n, m;
    cin >> n >> m;
    cout << (ok(n, m) ? "YES" : "NO") << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        Solution();
    }
}
