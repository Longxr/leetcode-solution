/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (61.79%)
 * Likes:    454
 * Dislikes: 0
 * Total Accepted:    109.9K
 * Total Submissions: 177K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */

// @lc code=start
class Solution {
public:
    int partition2(vector<int>& nums, int beg, int end){    //通过快排划分
      int index;
        if (beg < end) {
          index = rand() % (end - beg) + beg;
          swap(nums[index], nums[end]);
        }
        index = beg;            //index索引之后的值都比基准值大
        for(int i=beg;i<end;i++){
            if(nums[i]<=nums[end]){
                swap(nums[i], nums[index++]);
            }
        }
        swap(nums[index],nums[end]);
        return index;
    }
    int findKthLargest(vector<int> &nums, int k) {
        int size = nums.size();
        if (size <= 1) return nums[0]; 
        int target = size - k;

        int left = 0;
        int right = size - 1;
        while (true) {
            int p = partition2(nums, left, right);
            if (p == target) {
                return nums[p];
            } else if (target < p) {
                right = p - 1;
            } else {
                left = p + 1;
            }
        }
    }
};
// @lc code=end

