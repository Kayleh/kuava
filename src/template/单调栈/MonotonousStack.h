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