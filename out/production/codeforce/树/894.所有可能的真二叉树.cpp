/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的真二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        vector<TreeNode *> ans; // 存放所有可能的树
        if (n % 2 == 0)
            return ans; // 偶数个节点，不可能构成满二叉树
        if (n == 1)
        { 
            ans.push_back(new TreeNode(0)); // 只有一个节点，只有一种可能
            return ans;
        }
        for (int i = 1; i < n; i += 2)
        {
            vector<TreeNode *> left = allPossibleFBT(i); // 左子树的所有可能
            vector<TreeNode *> right = allPossibleFBT(n - i - 1); // 右子树的所有可能
            for (auto l : left) // 遍历左子树的所有可能
            {
                for (auto r : right) // 遍历右子树的所有可能
                {
                    TreeNode *root = new TreeNode(0); // 根节点
                    root->left = l; // 左子树
                    root->right = r; // 右子树
                    ans.push_back(root); // 加入结果集
                }
            }
        }
        return ans;
    }
};
// @lc code=end
