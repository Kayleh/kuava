using namespace std;
#include <bits/stdc++.h>
#define ull long long

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        ull N;
        cin >> N;
        cout << "N: " << bitset<64>(N) << endl;
        int cnt1 = __builtin_popcount(N); // N中1的个数
        if (cnt1 == 3)
        {
            cout << N << endl;
            continue;
        }

        int pos = -1; // 找到N的二进制表示中第3高位的1

        while (cnt1 > 3)
        {
            pos++;
            if (N & (1 << pos))
            {
                cnt1--;
            }
        }
        cout << "pos: " << pos << endl;

        cout << "a: " << bitset<64>(N) << endl;
        cout << "W: " << bitset<64>(936748722493063168) << endl;
        cout << N << endl;
    }

    return 0;
}
