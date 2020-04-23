/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.85%)
 * Likes:    1848
 * Dislikes: 0
 * Total Accepted:    202.4K
 * Total Submissions: 701.3K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2) {
            return s;
        }

        int maxLen = 1;
        string ret = s.substr(0, 1);

        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) { //s(i, j)是长度大于等于2的所有子串(j - i + 1是字符串长度)
                if ((j - i + 1) > maxLen && isPalindrome(s, i, j)) {
                    maxLen = j - i + 1;
                    ret = s.substr(i, j - i + 1);
                }
            }
        }
        return ret;
    }

    bool isPalindrome(const string &s, int left, int right) {       //判断子串是否为回文字符串
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end

