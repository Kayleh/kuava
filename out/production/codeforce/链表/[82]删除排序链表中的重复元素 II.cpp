//给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,3,4,4,5]
//输出：[1,2,5]
// 
//
// 示例 2： 
// 
// 
//输入：head = [1,1,1,2,3]
//输出：[2,3]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点数目在范围 [0, 300] 内 
// -100 <= Node.val <= 100 
// 题目数据保证链表已经按升序 排列 
// 
//
// Related Topics 链表 双指针 👍 1008 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(0, head); // 哑节点
        ListNode *cur = dummy; // 当前节点
        while (cur->next && cur->next->next) { // 当前节点的下一个节点和下下个节点都存在
            if (cur->next->val == cur->next->next->val) { // 如果当前节点的下一个节点和下下个节点的值相等
                int x = cur->next->val; // 记录重复值
                while (cur->next && cur->next->val == x) { // 当前节点的下一个节点存在且值等于重复值
                    cur->next = cur->next->next; // 删除当前节点的下一个节点
                }
            } else {
                cur = cur->next; // 当前节点后移
            }
        }
        return dummy->next; // 返回头节点
    }
};
//leetcode submit region end(Prohibit modification and deletion)
