/*
 * @lc app=leetcode.cn id=391 lang=c
 *
 * [391] 完美矩形
 *
 * https://leetcode.cn/problems/perfect-rectangle/description/
 *
 * algorithms
 * Hard (46.09%)
 * Likes:    261
 * Dislikes: 0
 * Total Accepted:    28.2K
 * Total Submissions: 61.3K
 * Testcase Example:  '[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]'
 *
 * 给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi]
 * 表示一个坐标轴平行的矩形。这个矩形的左下顶点是 (xi, yi) ，右上顶点是 (ai, bi) 。
 * 
 * 如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
 * 输出：true
 * 解释：5 个矩形一起可以精确地覆盖一个矩形区域。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
 * 输出：false
 * 解释：两个矩形之间有间隔，无法覆盖成一个矩形。
 * 
 * 示例 3：
 * 
 * 
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
 * 输出：false
 * 解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= rectangles.length <= 2 * 10^4
 * rectangles[i].length == 4
 * -10^5 <= xi, yi, ai, bi <= 10^5
 * 
 * 
 */

// @lc code=start
bool isRectangleCover(int** rectangles, int rectanglesSize, int* rectanglesColSize) {
    
}
// @lc code=end

