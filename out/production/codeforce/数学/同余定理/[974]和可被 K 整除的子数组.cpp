//给定一个整数数组 nums 和一个整数 k ，返回其中元素之和可被 k 整除的（连续、非空） 子数组 的数目。 
//
// 子数组 是数组的 连续 部分。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [4,5,0,-2,-3,1], k = 5
//输出：7
//解释：
//有 7 个子数组满足其元素之和可被 k = 5 整除：
//[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
// 
//
// 示例 2: 
//
// 
//输入: nums = [5], k = 9
//输出: 0
// 
//
// 
//
// 提示: 
//
// 
// 1 <= nums.length <= 3 * 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// 2 <= k <= 10⁴ 
// 
//
// Related Topics 数组 哈希表 前缀和 👍 394 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subarraysDivByK(vector<int> &nums, int k) {
        int ans = 0;
        unordered_map<int, int> map; // 余数，个数
        map[0] = 1;  // 余数为0的个数为1
        int sum = 0;
        for (int num: nums) {
            sum += num;
            // 根据同余定理，(a + b) % k = (a % k + b % k) % k，所以可以将前缀和对K取模，然后统计相同余数的个数
            // 所以在前缀和数组中，pre[i] % k = pre[i-1] % k，那么pre[i] - pre[i-1]就是一个可以被K整除的子数组
            int mod = (sum % k + k) % k; // 因为C++中负数取模的结果是负数，所以需要加上K
            if (map.count(mod)) { // 如果存在相同余数的前缀和
                ans += map[mod]; // 统计相同余数的个数
            }
            map[mod]++; // 更新余数的个数
        }
        // cout map
        for (auto &it: map) {
            cout << it.first << " " << it.second << endl;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
