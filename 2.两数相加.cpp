/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (36.86%)
 * Likes:    4019
 * Dislikes: 0
 * Total Accepted:    351.2K
 * Total Submissions: 952.8K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (nullptr == l1 && nullptr == l2) return nullptr;
        else if (nullptr == l1) return l2;
        else if (nullptr == l2) return l1;

        int sum = l1->val + l2->val;    //当前位数两位相加的结果
        ListNode* result = new ListNode(sum % 10);
        result->next = addTwoNumbers(l1->next, l2->next);  //递归求出后面位数的链表
        if (sum >= 10) {
            result->next = addTwoNumbers(result->next, new ListNode(1));  //如果有进位，再递归求结果，后面位数链表 + 进位（两位数求和相加不会有1以外的进位）
        }
        return result; 
    }
};
// @lc code=end

