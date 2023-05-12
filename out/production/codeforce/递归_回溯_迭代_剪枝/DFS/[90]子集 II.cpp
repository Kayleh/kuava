//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。 
//
// 
// 
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,2]
//输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// 
//
// Related Topics 位运算 数组 回溯 👍 952 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector <vector<int>> subsetsWithDup(vector<int> &nums) {
        vector <vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end()); // 注意去重的前提是数组有序
        dfs(nums, 0, path, res);
        return res;
    }

    /**
     *  递归函数
     *
     * @param nums
     * @param index
     * @param path
     * @param res
     */
    void dfs(vector<int> &nums, int index, vector<int> &path, vector <vector<int>> &res) {
        res.push_back(path);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue; // 去重
            path.push_back(nums[i]); // 选择
            dfs(nums, i + 1, path, res);
            path.pop_back(); // 回溯
        }
    }
};;
//leetcode submit region end(Prohibit modification and deletion)
