/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 *
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (50.39%)
 * Likes:    483
 * Dislikes: 0
 * Total Accepted:    80K
 * Total Submissions: 158.7K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 * 
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
 * 
 * 说明：不允许修改给定的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：tail connects to node index 1
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [1,2], pos = 0
 * 输出：tail connects to node index 0
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = [1], pos = -1
 * 输出：no cycle
 * 解释：链表中没有环。
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：
 * 你是否可以不用额外空间解决此题？
 * 
 */

// @lc code=start
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
    ListNode *detectCycle(ListNode *head) {
        unique_ptr<ListNode> dummy(new ListNode(-1));
        dummy->next=head;
        ListNode* fast, *slow;
        fast = slow = dummy.get();
        while (fast != nullptr && fast->next != nullptr && slow != nullptr) {
          slow = slow->next;
          fast = fast->next->next;
          if (fast == slow) break; 
        }

        //没有环的情况
        if (fast == nullptr || fast->next == nullptr || slow == nullptr) return nullptr;

        //有环时，设head到环起点距离为a, head到相交点距离为p, 环长度为c，则：a + p = nc
        //用个新指针从head开始，走a步会和慢指针相遇在环起点
        fast = dummy.get();
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return fast;
    }
};
// @lc code=end

