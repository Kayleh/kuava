//
// Created by w1z4Rd on 23/07/01.
//



using namespace std;

#include  <bits/stdc++.h>

int main() {

    int cnt = 1248;

    // 输出每一位
    while (cnt) {
        cout << cnt % 10 << endl;
        cnt /= 10;
    }
};