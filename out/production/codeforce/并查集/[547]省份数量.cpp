//
// 
// 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连
//。 
// 
// 
//
// 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。 
//
// 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 
//isConnected[i][j] = 0 表示二者不直接相连。 
//
// 返回矩阵中 省份 的数量。 
//
// 
//
// 示例 1： 
// 
// 
//输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
//输出：2
// 
//
// 示例 2： 
// 
// 
//输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 200 
// n == isConnected.length 
// n == isConnected[i].length 
// isConnected[i][j] 为 1 或 0 
// isConnected[i][i] == 1 
// isConnected[i][j] == isConnected[j][i] 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 👍 889 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class UnionFind{
public:
    int find(int x){
        int root = x;

        while(father[root] != -1){
            root = father[root];
        }

        while(x != root){
            int original_father = father[x];
            father[x] = root;
            x = original_father;
        }

        return root;
    }

    bool is_connected(int x,int y){
        return find(x) == find(y);
    }

    void merge(int x,int y){
        int root_x = find(x);
        int root_y = find(y);

        if(root_x != root_y){
            father[root_x] = root_y;
            num_of_sets--;
        }
    }

    void add(int x){
        if(!father.count(x)){
            father[x] = -1;
            num_of_sets++;
        }
    }

    int get_num_of_sets(){
        return num_of_sets;
    }

private:
    // 记录父节点
    unordered_map<int,int> father;
    // 记录集合数量
    int num_of_sets = 0;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind uf;
        for(int i = 0;i < isConnected.size();i++){
            uf.add(i);
            for(int j = 0;j < i;j++){
                if(isConnected[i][j]){
                    uf.merge(i,j);
                }
            }
        }

        return uf.get_num_of_sets();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
