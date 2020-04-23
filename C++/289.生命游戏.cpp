/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 *
 * https://leetcode-cn.com/problems/game-of-life/description/
 *
 * algorithms
 * Medium (69.68%)
 * Likes:    168
 * Dislikes: 0
 * Total Accepted:    27.2K
 * Total Submissions: 36.4K
 * Testcase Example:  '[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]'
 *
 * 根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
 * 
 * 给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0
 * 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
 * 
 * 
 * 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
 * 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
 * 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
 * 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
 * 
 * 
 * 
 * 根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入： 
 * [
 * [0,1,0],
 * [0,0,1],
 * [1,1,1],
 * [0,0,0]
 * ]
 * 输出：
 * [
 * [0,0,0],
 * [1,0,1],
 * [0,1,1],
 * [0,1,0]
 * ]
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
 * 本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        auto affectFunc = [&](int x, int y)->void { //计算某个位置对周围的影响值，活细胞使周围8格+10
            for (int i = x - 1; i <= x + 1; i++) {
                for (int j = y - 1; j <= y + 1; j++) {
                    if (i < 0 || i >= m || j < 0 || j >= n  || (i == x && j == y)) continue;
                    board[i][j] += 10;
                }
            }
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] % 10 == 1) {
                    affectFunc(i, j);
                }
            }
        }

        auto calculateFunc = [&](int x, int y)->void {
            int value = board[x][y];
            if (value / 10 == 3) {  //规则2
                board[x][y] = 1;
            } else if (value / 10 == 2 && value % 10 == 1) {    //规则4
                board[x][y] = 1;
            } else {
                board[x][y] = 0;    //规则1，3
            }
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                calculateFunc(i, j);
            }
        }
    }
};
// @lc code=end

