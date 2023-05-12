/*
 * @lc app=leetcode.cn id=2331 lang=cpp
 *
 * [2331] 计算布尔二叉树的值
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
    bool evaluateTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            // 如果是叶子节点，直接返回
            return root->val == 1;
        }
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        if (root->val == 3)
        {
            return left && right;
        }
        else if (root->val == 2)
        {
            return left || right;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
