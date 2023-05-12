//给你一个下标从 0 开始的整数数组 nums ，请你找出一个下标从 0 开始的整数数组 answer ，其中： 
//
// 
// answer.length == nums.length 
// answer[i] = |leftSum[i] - rightSum[i]| 
// 
//
// 其中： 
//
// 
// leftSum[i] 是数组 nums 中下标 i 左侧元素之和。如果不存在对应的元素，leftSum[i] = 0 。 
// rightSum[i] 是数组 nums 中下标 i 右侧元素之和。如果不存在对应的元素，rightSum[i] = 0 。 
// 
//
// 返回数组 answer 。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [10,4,8,3]
//输出：[15,1,11,22]
//解释：数组 leftSum 为 [0,10,14,22] 且数组 rightSum 为 [15,11,3,0] 。
//数组 answer 为 [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22] 。
// 
//
// 示例 2： 
//
// 输入：nums = [1]
//输出：[0]
//解释：数组 leftSum 为 [0] 且数组 rightSum 为 [0] 。
//数组 answer 为 [|0 - 0|] = [0] 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 1000 
// 1 <= nums[i] <= 10⁵ 
// 
//
// Related Topics 数组 前缀和 👍 8 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// @lc code=start
class Solution {
public:
    vector<int> leftRigthDifference(vector<int> &nums) {
        vector<int> leftSum;
        vector<int> rightSum;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            leftSum.push_back(sum);
            sum += nums[i];
        }
        sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            rightSum.push_back(sum);
            sum += nums[i];
        }
        reverse(rightSum.begin(), rightSum.end());
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++) {
            answer.push_back(abs(leftSum[i] - rightSum[i]));
        }
        return answer;
    }
};
;
//leetcode submit region end(Prohibit modification and deletion)
