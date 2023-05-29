using namespace std;
#include <bits/stdc++.h>
#define ull long long

int main()
{
    // 给你一个正整数N,判断是否有一个小于或等于N的正整数,使得X 的二进制表示中的 1 的个数为 3，并找出满足条件的最大 X,如果不存在这样的 X,则输出 -1

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        ull s;
        ull ans = 0;
        cin >> s;
        string N = bitset<64>(s).to_string();
        int l = -1; // l为最高的1的位置
        ull cutCnt = 0;

        for (int j = 0; j < 65; ++j)
        {
            if (N[j] == '1')
            {
                if (l == -1)
                    l = j;
                cutCnt++;
            }
        }
        if (cutCnt == 3)
        {
            cout << s << endl;
            continue;
        }
        if (l < 3)
        {
            cout << -1 << endl;
            continue;
        }

        N[l] = '0';
        int cnt = 3;
        for (ull j = l + 1; j < 65; ++j)
        {

            if (N[j] == '1' && cnt > 0)
                continue;
            if (N[j] == '0' && cnt > 0)
            {
                N[j] = '1';
                cnt--;
            }
            else if (cnt == 0)
            {
                N[j] = '0';
            }
        }

        if (cnt)
        {
            cout << -1 << endl;
            continue;
        }
        ans = 0;
        for (int j = 0; j < 65; ++j)
        {
            if (N[j] == '1')
                ans += pow(2, 64 - j - 1); // 64 - j - 1 为当前位的权重
        }
        if (cnt)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
