//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,6,3,4,5,6], val = 6
//输出：[1,2,3,4,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [], val = 1
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [7,7,7,7], val = 7
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 列表中的节点数目在范围 [0, 10⁴] 内 
// 1 <= Node.val <= 50 
// 0 <= val <= 50 
// 
//
// Related Topics 递归 链表 👍 1073 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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

//leetcode submit region end(Prohibit modification and deletion)
