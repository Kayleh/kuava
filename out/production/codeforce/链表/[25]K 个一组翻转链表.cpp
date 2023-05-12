//给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。 
//
// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 
//
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[2,1,4,3,5]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [1,2,3,4,5], k = 3
//输出：[3,2,1,4,5]
// 
//
// 
//提示：
//
// 
// 链表中的节点数目为 n 
// 1 <= k <= n <= 5000 
// 0 <= Node.val <= 1000 
// 
//
// 
//
// 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？ 
//
// 
// 
//
// Related Topics 递归 链表 👍 1832 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)
