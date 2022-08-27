/*
 *  $ codeforce  2022-08-26
 *
 *  Copyright 2022  Kayleh. All rights reserved.
 *  @see {@link https://github.com/Kayleh/kuava}
 *
 */

package template.Java.struct;

import javafx.util.Pair;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/**
 * @brief 二叉树节点
 */
public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode(int x) {
        val = x;
    }


    /**
     * 对二叉树编号(满二叉树)
     */
    public void number() {
        List<List<Pair<Integer, TreeNode>>> ans = new ArrayList<>();
        //bfs(ans, this, 1);
        dfs(ans, this, 1);
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

    private void dfs(List<List<Pair<Integer, TreeNode>>> ans, TreeNode treeNode, int i) {
        if (treeNode == null) {
            return;
        }

        dfs(ans, treeNode.left, i << 1);
        dfs(ans, treeNode.right, i << 1 + 1);
    }
}
