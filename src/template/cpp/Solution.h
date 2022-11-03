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
#define euclideanDistance(x1, y1, x2, y2) sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))//欧几里得距离
/*struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};*/

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *dummy = new ListNode(-1); // 哨兵节点, 用于处理头节点
        dummy->next = head; // 哨兵节点指向头节点
        ListNode *cur = dummy;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {    // 如果当前节点的下一个节点的值等于val, 则删除下一个节点
                ListNode *delNode = cur->next; // 删除节点
                cur->next = delNode->next;   // 当前节点指向删除节点的下一个节点
                delete delNode; // 删除节点
            } else {
                cur = cur->next; // 当前节点指向下一个节点
            }
        }
        ListNode *retNode = dummy->next; // 保存头结点
        delete dummy; // 释放虚拟头结点
        return retNode;
    }
};
