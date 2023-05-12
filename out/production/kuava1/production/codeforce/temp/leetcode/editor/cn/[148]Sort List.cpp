//Given the head of a linked list, return the list after sorting it in 
//ascending order. 
//
// 
// Example 1: 
// 
// 
//Input: head = [4,2,1,3]
//Output: [1,2,3,4]
// 
//
// Example 2: 
// 
// 
//Input: head = [-1,5,3,4,0]
//Output: [-1,0,3,4,5]
// 
//
// Example 3: 
//
// 
//Input: head = []
//Output: []
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [0, 5 * 10⁴]. 
// -10⁵ <= Node.val <= 10⁵ 
// 
//
// 
// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.
//e. constant space)? 
//


using namespace std;

#include "bits/stdc++.h"

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // 快慢指针可以找到链表的中间节点，从而将链表分为两个部分
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr; // 断开链表 为了后面的递归
        ListNode *left = sortList(head); // 递归排序左边
        ListNode *right = sortList(slow); // 递归排序右边
        return merge(left, right);
    }

    /**
     * 合并两个有序链表
     * @param left
     * @param right
     * @return
     */
    ListNode *merge(ListNode *left, ListNode *right) {
        // 我们需要返回的是头节点，而头节点可能会发生变化，所以我们需要一个虚拟头节点
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (left != nullptr && right != nullptr) { // 两个链表都不为空
            if (left->val < right->val) {
                cur->next = left;
                left = left->next; //将节点放到新链表中,移动左链表的指针
            } else {
                cur->next = right;
                right = right->next;//将节点放到新链表中,移动右链表的指针
            }
            cur = cur->next; // 移动新链表的指针
        }
        if (left != nullptr) {
            cur->next = left; // 将剩余的节点放到新链表中
        }
        if (right != nullptr) {
            cur->next = right; // 将剩余的节点放到新链表中
        }
        return dummy->next;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
