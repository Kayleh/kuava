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

int a[3];
int main()
{
    cin >> a[0] >> a[1] >> a[2];

    sort(a, a + 3);

    cout << a[0] << " " << a[1] << " " << a[2];
}
