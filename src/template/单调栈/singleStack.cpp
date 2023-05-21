#include <bits/stdc++.h>
using namespace std;

/**
 * 单调栈
 * 栈内元素单调递增或者单调递减的数据结构
 */

/**
 * 求解nums1中每个元素在num2的下一个更大元素
 * @param nums1
 * @param nums2
 * @return
 */
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    stack<int> stack;
    unordered_map<int, int> map;
    for (int i = 0; i < nums2.size(); i++)
    {
        while (!stack.empty())
        {
            int top = stack.top();
            if (nums2[top] < nums2[i])
            {
                map[nums2[top]] = nums2[i];
                stack.pop();
            }
            else
            {
                break;
            }
        }
        stack.push(i);
    }
    while (!stack.empty())
    {
        int top = stack.top();
        map[nums2[top]] = -1;
        stack.pop();
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(map[nums1[i]]);
    }
    return ans;
}

/**
 * 第i个元素的下一个更大元素
 *
 *  in： 1 4 2 3 5
 *  out：2 5 4 5 0
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums[i] = num;
    }

    stack<int> stack; // 单调栈
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        int cur = nums[i];

        while (!stack.empty())
        {
            int top = stack.top();
            if (nums[top] < cur)
            {
                ans[top] = i;
                stack.pop();
            }
            else
            {
                break;
            }
        }
        stack.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] + 1 << " ";
    }

    return 0;
}
