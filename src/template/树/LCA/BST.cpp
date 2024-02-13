#include "../Tree.h"

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
    TreeNode *BST_LCA(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr; // 递归终止条件
        if (root->val > p->val && root->val > q->val)
        { // p,q 都在 root 的左子树中
            return BST_LCA(root->left, p, q);
        }
        if (root->val < p->val && root->val < q->val)
        { // p,q 都在 root 的右子树中
            return BST_LCA(root->right, p, q);
        }
        return root;
    }
};