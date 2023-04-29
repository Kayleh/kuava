/*
 *  $ codeforce  2022-08-27
 *
 *  Copyright 2022  Kayleh. All rights reserved.
 *  @see {@link https://github.com/Kayleh/kuava}
 *
 */

package template.Java.struct.Tree;

import java.util.List;

/**
 * @brief n叉树节点
 */
public class NTreeNode {
    public int val;
    public List<NTreeNode> children;

    public NTreeNode(int val, List<NTreeNode> children) {
        this.val = val;
        this.children = children;
    }
}
