#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>

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

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;


// ———————————————— Solution ————————————————

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < points.size(); i++) {
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            q.push({dis, i});
            if (q.size() > k) {
                q.pop();
            }
        }
        while (!q.empty()) {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }
};

// ———————————————— Main ————————————————

int main() {
    Solution solution;
    vector<string> nums = vector<string>();
    nums.push_back("01");
    nums.push_back("10");
    string basicString = solution.findDifferentBinaryString(nums);
    cout << basicString << endl;
    return 0;
}



