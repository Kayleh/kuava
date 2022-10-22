#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;  // 这里是为了方便处理，dummy->next = head，这样就不用考虑头结点的问题了
        ListNode *pre = dummy; // pre指向每一组的前一个节点
        ListNode *end = dummy; // end指向每一组的最后一个节点
        while (end->next != nullptr) {
            for (int i = 0; i < k && end != nullptr; i++) end = end->next; // 找到第k个节点，end指向第k个节点
            if (end == nullptr) break; // 如果end为空，说明剩余节点不足k个，不需要反转，直接退出
            ListNode *start = pre->next; // start指向每一组的第一个节点
            ListNode *next = end->next; // next指向下一组的第一个节点
            end->next = nullptr; // 断开链表
            pre->next = reverse(start); // 反转链表
            start->next = next; // 将反转后的链表和下一组的链表连接起来
            pre = start;    // pre指向下一组的前一个节点
            end = pre;      // end指向下一组的最后一个节点
        }
        return dummy->next;
    }

    /**
     * @brief 反转链表
     * @param head  链表头节点
     * @return
     */
    ListNode *reverse(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

int main() {
    Solution solution;
    vector<int> nums = vector<int>();
    int res = solution.isValid(nums);
    cout << res << endl;
    return 0;
}

