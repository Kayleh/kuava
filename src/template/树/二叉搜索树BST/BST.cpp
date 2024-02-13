using namespace std;
#include <bits/stdc++.h>

class Solution
{
public:
    /**
     * @brief 构造二叉搜索树
     *
     * @param nodes
     * @return TreeNode*
     */
    TreeNode *balanceBST(vector<int> nodes)
    {
        sort(nodes.begin(), nodes.end());
        function<TreeNode *(int, int)> build = [&](int l, int r)
        {
            if (l > r)
                return (TreeNode *)nullptr;
            int mid = (l + r) >> 1;
            TreeNode *root = new TreeNode(nodes[mid]);
            root->left = build(l, mid - 1);
            root->right = build(mid + 1, r);
            return root;
        };
        root = build(0, nodes.size() - 1);
        return root;
    }
};