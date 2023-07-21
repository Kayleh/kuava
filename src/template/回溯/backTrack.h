//
// Created by w1z4Rd on 2022/11/1.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> t; // 用于保存当前的路径
    vector <vector<int>> ans; // 用于保存所有的路径

    /**
     * 查询所有nums的子集(不重复)
     * @param nums
     * @return
     */
    vector <vector<int>> subsets(vector<int> &nums) {
        dfs(0, nums);
        return ans;
    }

    /**
     * 查询以 cur 为起点的所有子集
     * @param cur
     * @param nums
     */
    void dfs(int cur, vector<int> &nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]); // 考虑选择当前位置
        dfs(cur + 1, nums);
        t.pop_back();           // 考虑不选择当前位置
        dfs(cur + 1, nums);
    }
};