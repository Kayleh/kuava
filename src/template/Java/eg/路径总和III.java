package template.Java.eg;//给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
//
// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
//
//
//
// 示例 1：
//
//
//
//
//输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
//输出：3
//解释：和等于 8 的路径有 3 条，如图所示。
//
//
// 示例 2：
//
//
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：3
//
//
//
//
// 提示:
//
//
// 二叉树的节点个数的范围是 [0,1000]
//
// -10⁹ <= Node.val <= 10⁹
// -1000 <= targetSum <= 1000
//
//
// Related Topics 树 深度优先搜索 二叉树 👍 1442 👎 0


import template.Java.struct.Tree.TreeNode;

//leetcode submit region begin(Prohibit modification and deletion)
public class 路径总和III {
    /**
     * 返回以这个节点为根的树中，和为目标值的路径总数。
     *
     * @param root      节点
     * @param targetSum 目标值
     * @return
     */
    public int pathSum(TreeNode root, int targetSum) {
        if (null == root) return 0;
        // 答案 = 当前节点的路径数 + 左子树的路径数 + 右子树的路径数
        return dfs(root, targetSum) + pathSum(root.left, targetSum) + pathSum(root.right, targetSum);
    }

    /**
     * 返回以这个节点为根的树中，能凑出几个以该节点为路径开头，和为目标值的路径总数。
     *
     * @param root      节点
     * @param targetSum 目标值
     * @return
     */
    int dfs(TreeNode root, long targetSum) {
        if (null == root) return 0;
        // 当前节点的路径数 = 当前节点的值 + 左子树的路径数 + 右子树的路径数
        return ((root.val == targetSum) ? 1 : 0)
                + dfs(root.left, targetSum - root.val)
                + dfs(root.right, targetSum - root.val);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
