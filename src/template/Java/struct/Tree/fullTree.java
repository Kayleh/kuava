/*
 *  $ codeforce  2022-08-27
 *
 *  Copyright 2022  Kayleh. All rights reserved.
 *  @see {@link https://github.com/Kayleh/kuava}
 *
 */

package template.Java.struct.Tree;

import javafx.util.Pair;

import java.util.*;

/**
 * @brief 满二叉树
 */
public class fullTree {
    /**
     * 对二叉树编号(满二叉树)
     */
    public void number() {
        List<List<Pair<Integer, TreeNode>>> ans = new ArrayList<>();
        //bfs(ans, this, 1);
//        dfs(ans, this, 1);
    }

    void bfs(List<List<Pair<Integer, TreeNode>>> ans, TreeNode root, int index) {
        if (root == null) {
            return;
        }
        // key:编号 value:节点
        Deque<Pair<Integer, TreeNode>> queue = new ArrayDeque<>();
        queue.addLast(new Pair<>(1, root));
        while (!queue.isEmpty()) {
            int max = 0, min = 0;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Pair<Integer, TreeNode> pair = queue.removeFirst();
                int code = pair.getKey();
                TreeNode node = pair.getValue();
                if (i == 0) min = code;//第一个节点的编号
                if (i == size - 1) max = code;//最后一个节点的编号
                if (node.left != null) {
                    //左孩子编号是父节点编号的两倍，即  left=2×root
                    queue.addLast(new Pair<>(code << 1, node.left));
                }
                if (node.right != null) {
                    //右孩子编号是父节点编号的两倍加一，即 right=2×root+1
                    queue.addLast(new Pair<>((code << 1) + 1, node.right));
                }
                ans.add(new ArrayList<>(queue));
            }
        }
    }

    Map<Integer, Integer> map = new HashMap<>();
    int ans;

    public int widthOfBinaryTree(TreeNode root) {
        dfs(root, 1, 0);
        return ans;
    }

    void dfs(TreeNode root, int u, int depth) {
        if (root == null) return;
        if (!map.containsKey(depth)) map.put(depth, u);
        ans = Math.max(ans, u - map.get(depth) + 1);
        u = u - map.get(depth) + 1;
        dfs(root.left, u << 1, depth + 1);
        dfs(root.right, u << 1 | 1, depth + 1);
    }
}
