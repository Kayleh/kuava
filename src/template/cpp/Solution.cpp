#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>

#define gcd(a, b) __gcd(a, b) // 最大公约数
#define bitcount(a) __builtin_popcount(a) // 二进制中1的个数
#define lcm(a, b) (a * b / gcd(a, b)) // 最小公倍数
#define max(a, b) (a > b ? a : b) // 最大值
#define min(a, b) (a < b ? a : b) // 最小值
#define abs(a) (a > 0 ? a : -a) // 绝对值
#define swap(a, b) {int t = a; a = b; b = t;} // 交换
#define rep(i, a, b) for (int i = a; i <= b; i++) // 递增
#define per(i, a, b) for (int i = a; i >= b; i--) // 递减
#define forin(i, a) for (auto i : a) // 遍历
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
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // dp[i][j] 表示 nums1[0..i-1] 和 nums2[0..j-1] 的最长公共子序列
        for (int i = 1; i <= m; i++) {
            int num1 = nums1[i - 1];
            for (int j = 1; j <= n; j++) {
                int num2 = nums2[j - 1];
                if (num1 == num2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1; // 如果两个数相等，那么最长公共子序列就是两个数之前的最长公共子序列加1
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 两个序列都不包含 nums1[i-1] 和 nums2[j-1]
                }
            }
        }
        return dp[m][n];
    }
};







// ———————————————— Main ————————————————

int main() {
    Solution solution;
    int numa, numb;
    cin >> numa >> numb;
    solution.solution(numa, numb);
    cout << solution.solution(numa, numb) << endl;
    return 0;
}



