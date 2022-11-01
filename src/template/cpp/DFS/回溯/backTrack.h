//
// Created by w1z4Rd on 2022/11/1.
//

using namespace std;

class Solution {
public:
    vector <vector<int>> subsetsWithDup(vector<int> &nums) {
        vector <vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
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
};