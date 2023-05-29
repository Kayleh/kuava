#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void findXY(int n, int k) {
    if (k >= n) {
        cout << -1 << endl;
        return;
    }

    // 尝试每个可能的 x 值
    for (int x = k; x < n; x++) {
        int y = n - x;
        if (x % y == k) {
            cout << x << " " << y << endl;
            return;
        }
    }

    cout << -1 << endl;
}


int main() {
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        //  给定正整数n,k.
        //  输出x,y  满足(x+y=n) and (x % y=k)
        //  如果没有这样的x和y，输出-1
        long long n, k;
        cin >> n >> k;
        findXY(n, k);
    }
    return 0;
}