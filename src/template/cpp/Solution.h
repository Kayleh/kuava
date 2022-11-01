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

#define PI 3.14159265358979323846
#define gcd(a, b) __gcd(a, b)             // 最大公约数
#define bitcount(a) __builtin_popcount(a) // 二进制中1的个数
#define lcm(a, b) (a * b / gcd(a, b))     // 最小公倍数
#define max(a, b) (a > b ? a : b)         // 最大值
#define min(a, b) (a < b ? a : b)         // 最小值
#define abs(a) (a > 0 ? a : -a)           // 绝对值
#define swap(a, b) (a ^= b ; b ^= a ; a ^= b) // 交换
#define rep(i, from, to) for (int i = from; i <= to; i++) // 递增
#define per(i, from, to) for (int i = from; i >= to; i--) // 递减
#define forin(item, arr) for (auto item : arr)            // 遍历
#define ll long long
#define ull unsigned long long
#define changeCase(c) (c ^ (1 << 5)) // 大小写互换
#define isLetter(c) (isalpha(c))      // 判断是否为字母
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
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, path, res);
        return res;
    }

    /**
     *  递归函数
     *
     * @param nums
     * @param index
     * @param path
     * @param res
     */
    void dfs(vector<int> &nums, int index, vector<int> &path, vector<vector<int>> &res) {
        res.push_back(path);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue; // 去重
            path.push_back(nums[i]); // 选择
            dfs(nums, i + 1, path, res);
            path.pop_back(); // 回溯
        }
    }
};
