#include <bits/stdc++.h>
using namespace std;

/**
 * 单调栈
 * 栈内元素单调递增或者单调递减的数据结构
 */
class MonotonousStack
{
private:
    stack<int> stack;
    vector<int> nums; // 输入数组
public:
    MonotonousStack(vector<int> nums);
    ~MonotonousStack();

    /**
     * 求解nums1中每个元素在num2的下一个更大元素
     * @param nums1
     * @param nums2
     * @return
     */
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> map; // key: num, value: num的下一个更大元素
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stack.empty() && ss.top() <= nums2[i])
                stack.pop();
            map[nums2[i]] = stack.empty() ? -1 : stack.top();
            stack.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++)
            nums1[i] = map[nums1[i]];
        return nums1;
    }

    /**
     * 返回 nums 中每个元素右边第一个比它大的元素
     * @description: 单调栈
     * @param {type}
     */
    vector<int> getLeft()
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (!stack.empty())
            {
                int top = stack.top();
                if (nums[top] < nums[i])
                {
                    ans[top] = i + 1; // 找到右边界
                    stack.pop();
                }
                else
                {
                    break;
                }
            }
            stack.push(i);
        }
        return ans;
    }
};

MonotonousStack::MonotonousStack(vector<int> nums)
{
    this->nums = nums;
}