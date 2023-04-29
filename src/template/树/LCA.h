//
// Created by w1z4Rd on 2022/11/5.
//

#ifndef KUAVA_LCA_H
#define KUAVA_LCA_H

#endif // KUAVA_LCA_H

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    /**
     * 二叉搜索树的最近公共祖先
     * @param root  根节点
     * @param p     节点 p
     * @param q     节点 q
     * @return
     */
    TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr; // 递归终止条件
        if (root->val > p->val && root->val > q->val)
        { // p,q 都在 root 的左子树中
            return LCA(root->left, p, q);
        }
        if (root->val < p->val && root->val < q->val)
        { // p,q 都在 root 的右子树中
            return LCA(root->right, p, q);
        }
        return root;
    }
};