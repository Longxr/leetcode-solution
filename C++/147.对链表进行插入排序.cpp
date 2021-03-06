/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 *
 * https://leetcode-cn.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (63.92%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    26.7K
 * Total Submissions: 41.7K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 对链表进行插入排序。
 * 
 * 
 * 插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
 * 每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
 * 
 * 
 * 
 * 插入排序算法：
 * 
 * 
 * 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
 * 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
 * 重复直到所有输入数据插入完为止。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2：
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
 * 
 * 
 */

// @lc code=start
/* *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* pre = dummy, *cur = head;
      while (cur) {
        if ((cur->next) && (cur->val > cur->next->val)) {//cur->next为待插入节点
          while ((pre->next) && (pre->next->val < cur->next->val)) {
            pre = pre->next;
          }
          //swap
          // ListNode* tmp = pre->next;
          // pre->next = cur->next;    //排好序部分前部指向待插入节点
          // cur->next = cur->next->next;//待插入节点从之前位置移除
          // pre->next->next = tmp;  //待插入节点指向排好序部分的后部

          ListNode* tmp = cur->next;
          cur->next = cur->next->next;  //待插入节点从之前位置移除
          tmp->next = pre->next;        //待插入节点指向排好序部分的后部
          pre->next = tmp;              //排好序部分前部指向待插入节点
          
          pre = dummy;
        } else {
          cur = cur->next;
        }
      } 
      return dummy->next; 
    }
};
// @lc code=end

