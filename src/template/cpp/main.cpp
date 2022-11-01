//
// Created by w1z4Rd on 2022/10/27.
//

//#include "Solution.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>
//#include <cassert>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int y, m;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
        string s1, s2;
        for (const auto &item: word1) {
            s1 += item;
        }
        for (const auto &item: word2) {
            s2 += item;
        }
        return s1 == s2;
    }
};

int main() {
    int day[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> y >> m;
    bool is = run(y);
    if (m == 2 && !is) {
        cout << 28 << endl;
    } else {
        cout << day[m - 1] << endl;
    }
    return 0;
}