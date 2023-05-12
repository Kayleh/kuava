//给定二叉搜索树（BST）的根节点
// root 和要插入树中的值
// value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。 
//
// 注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [4,2,7,1,3], val = 5
//输出：[4,2,7,1,3,5]
//解释：另一个满足题目要求可以通过的树是：
//
// 
//
// 示例 2： 
//
// 
//输入：root = [40,20,60,10,30,50,70], val = 25
//输出：[40,20,60,10,30,50,70,null,null,25]
// 
//
// 示例 3： 
//
// 
//输入：root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
//输出：[4,2,7,1,3,5]
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数将在
// [0, 10⁴]的范围内。
// 
// -10⁸ <= Node.val <= 10⁸ 
// 所有值 
// Node.val 是 独一无二 的。 
// -10⁸ <= val <= 10⁸ 
// 保证 val 在原始BST中不存在。 
// 
//
// Related Topics 树 二叉搜索树 二叉树 👍 390 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
class Solution {
public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == nullptr)return new TreeNode(val);
        // 非递归
        TreeNode *cur = root;
        while (cur != nullptr) {
            if (cur->val > val) { // 如果当前节点的值大于val，那么就往左子树找
                if (cur->left == nullptr) {
                    cur->left = new TreeNode(val); // 如果左子树为空，那么就直接插入
                    break;
                } else {
                    cur = cur->left;
                }
            } else {
                if (cur->right == nullptr) {
                    cur->right = new TreeNode(val);
                    break;
                } else {
                    cur = cur->right;
                }
            }
        }
        return root;
    }

    TreeNode *insertIntoBST2(TreeNode *root, int val) {
        if (root == nullptr)return new TreeNode(val);
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
