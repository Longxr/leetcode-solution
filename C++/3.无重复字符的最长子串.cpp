/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.26%)
 * Likes:    3275
 * Dislikes: 0
 * Total Accepted:    380.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

// @lc code=start
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         // 创建一个 key-value 为 字符-下标 相映射的哈希表
//         unordered_map<char,int> map;
//         int left = 0, right = 0, maxLen = 0;
//         for (right = 0; right < s.length(); right++){
//             // 判断是否存在该key
//             if(map.find(s[right]) != map.end()){
//                left = max(map.at(s[right]) + 1,left); //重复字符串左边那个的索引后一位
//             }
//             maxLen = max(maxLen, right - left + 1);
//             map[s[right]] = right;      //将当前扫描到的字符的下标添加到map
//         }
//         return maxLen;
//     }
// };
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool charFlag[256] = {0};
        int l = 0, r = -1; //滑动窗口为s[l...r]
        int res = 0;
        // 整个循环从 l == 0; r == -1 这个空窗口开始
        // 到l == s.size(); r == s.size()-1 这个空窗口截止
        // 在每次循环里逐渐改变窗口, 维护charFlag, 并记录当前窗口中是否找到了一个新的最优值
        while(l < s.size()){
            if(r + 1 < s.size() && charFlag[s[r+1]] == false){
                r++;
                charFlag[s[r]] = true;
            }else {   //r已经到头 || s[r+1] 在charFlag中，即字符重复
                charFlag[s[l]] = false;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
// @lc code=end

