#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>
#include <cassert>

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
    }                                                     // 交换
#define rep(i, from, to) for (int i = from; i <= to; i++) // 递增
#define per(i, from, to) for (int i = from; i >= to; i--) // 递减
#define forin(item, arr) for (auto item : arr)            // 遍历
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

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        unordered_map<int, int> row[9], col[9], box[9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num != '.') {
                    int n = num - '0' - 1, k = i / 3 * 3 + j / 3;
                    row[i][n]++;
                    col[j][n]++;
                    box[k][n]++;
                    if (row[i][n] > 1 || col[j][n] > 1 || box[k][n] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};;