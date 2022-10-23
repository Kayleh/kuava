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
    int balancedStringSplit(string s) {
        stack<char> st;
        int ans = 0;
        for (const auto &item: s) {
            if (st.empty()) {
                st.push(item);
            } else {
                if (st.top() == item) { // 相同则入栈
                    st.push(item);
                } else {
                    st.pop(); // 不同则出栈
                    if (st.empty()) { // 如果栈空了，说明已经平衡了
                        ans++; // 答案加一
                    }
                }
            }
        }
        return ans;
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



