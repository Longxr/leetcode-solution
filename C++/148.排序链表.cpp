/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (64.94%)
 * Likes:    504
 * Dislikes: 0
 * Total Accepted:    55.4K
 * Total Submissions: 85.3K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 
 * 示例 1:
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2:
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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

//递归指针版
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode*slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        return mergeTwoList(sortList(head), sortList(fast));
    }
    //方法一
    // ListNode* mergeTwoList(ListNode* h1, ListNode* h2) {
    //     if(!h1) return h2;
    //     if(!h2) return h1;
    //     if(h1->val < h2->val) {
    //         h1->next = mergeTwoList(h1->next, h2);
    //         return h1;
    //     }
    //     else {
    //         h2->next = mergeTwoList(h1, h2->next);
    //         return h2;
    //     }
    // }
    //方法二
    ListNode* mergeTwoList(ListNode* h1, ListNode* h2) {
        ListNode * dummy = new ListNode(0);
        ListNode* cur = dummy;
        
        while (h1 && h2) {
            if (h1->val < h2->val) {
                cur->next = h1;
                h1 = h1->next;
            } else {
                cur->next = h2;
                h2 = h2->next;
            }    
            cur = cur->next;
        }
        
        if (h1)
            cur->next = h1;
        else
            cur->next = h2;
            
        return dummy->next;
    }
};


// @lc code=end

