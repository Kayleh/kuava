/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
 */

#include <bits/stdc++.h>

// @lc code=start

class Solution {
public:
    //求当前结点的深度
    int depth(TreeNode* root){
        if(!root) return 0;

        int left = depth(root->left);
        int right = depth(root->right);

        return 1+max(left, right);

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return NULL;

        int left = depth(root->left); //左树深度
        int right = depth(root->right); //右树深度

        if(left == right){ //如果左右两边深度相等，那么当前结点就是最近公共祖先
            return root;
        }
        else if(left>right){ //左边更深，那么就去左边找
            return lcaDeepestLeaves(root->left);
        }
        else{
            return lcaDeepestLeaves(root->right);
        }
    }
};
// @lc code=end
