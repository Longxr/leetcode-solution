/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode-cn.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (51.00%)
 * Likes:    332
 * Dislikes: 0
 * Total Accepted:    37.7K
 * Total Submissions: 73.9K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
 * 
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
 * 
 * 给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 2, [[1,0]] 
 * 输出: true
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
 * 
 * 示例 2:
 * 
 * 输入: 2, [[1,0],[0,1]]
 * 输出: false
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。详情请参见图的表示法。
 * 你可以假定输入的先决条件中没有重复的边。
 * 1 <= numCourses <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //拓扑排序，判断有无环,三步走
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][0]]++;                 //step1  统计每个点的入度
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){                               //step2 将入度为0的点加进队列
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            cnt++;
            for(int i=0;i<prerequisites.size();i++){
                if(prerequisites[i][1]==front){
                    indegree[prerequisites[i][0]]--;        //更新与之相连的点的入度
                    if(indegree[prerequisites[i][0]]==0){   //step3  若更新后为0，又加进队列
                        q.push(prerequisites[i][0]);
                    }
                }
            }
        }
        return cnt==numCourses;   //比较加入队列的个数与点的个数
    }
};
// @lc code=end

