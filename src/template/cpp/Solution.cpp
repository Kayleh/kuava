#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>

#define PI 3.14159265358979323846
#define gcd(a, b) __gcd(a, b)             // 最大公约数
#define bitcount(a) __builtin_popcount(a) // 二进制中1的个数
#define lcm(a, b) (a * b / gcd(a, b))     // 最小公倍数
#define max(a, b) (a > b ? a : b)         // 最大值
#define min(a, b) (a < b ? a : b)         // 最小值
#define abs(a) (a > 0 ? a : -a)           // 绝对值
#define swap(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }                                             // 交换
#define rep(i, a, b) for (int i = a; i <= b; i++) // 递增
#define per(i, a, b) for (int i = a; i >= b; i--) // 递减
#define forin(i, a) for (auto i : a)              // 遍历
#define ll long long
#define ull unsigned long long

/*struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};*/

using namespace std;


// ———————————————— Solution ————————————————


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        if (firstList.empty() || secondList.empty()) return {};
        vector<vector<int>> res;
        int i = 0, j = 0; // 双指针
        while (i < firstList.size() && j < secondList.size()) {
            int left = max(firstList[i][0], secondList[j][0]); // 左边界
            int right = min(firstList[i][1], secondList[j][1]); // 右边界
            if (left <= right) res.push_back({left, right}); // 有交集
            (firstList[i][1] < secondList[j][1] ? i : j)++;
        }
        return res;
    }
};


// ———————————————— Main ————————————————
#include <stdio.h>
#include <stdlib.h>

int class1, class2, class3;

int main() {

};
