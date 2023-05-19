using namespace std;
#include <bits/stdc++.h>

void Solution()
{
    int n; // nums of elements
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    int maxLeft = 0, maxRight = 0;
    // 1. 找到最后一段递减的区间
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            maxLeft = i;
            break;
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] < a[i - 1])
        {
            maxRight = i;
            break;
        }
    }
    // 2. 交换区间
    vector<int> res;
    for (int i = maxLeft; i <= maxRight; i++)
        res.push_back(a[i]);
    for (int i = 0; i < maxLeft; i++)
        res.push_back(a[i]);
    for (int i = maxRight + 1; i < n; i++)
        res.push_back(a[i]);



    // 3. 输出
    for (auto x : res)
        cout << x << " ";
    cout << endl;
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