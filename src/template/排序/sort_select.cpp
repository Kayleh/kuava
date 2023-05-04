using namespace std;
#include <bits/stdc++.h>

/**
 * 选择排序
 * @brief  每次从未排序的部分选择最小的元素，放到已排序的部分的末尾
 * @时间复杂度  O(n^2)
 * @空间复杂度  O(1)
 */
class SelectSort
{
public:
    void sort(vector<int> &nums)
    {
        int n = nums.size();
        int cur = 0; // 已排序的部分的末尾
        while (cur < n)
        {
            int minIndex = cur; // 最小元素的索引
            for (int i = cur + 1; i < n; i++)
            {
                if (nums[i] < nums[minIndex])
                    minIndex = i;
            }
            swap(nums[cur], nums[minIndex]);
            cur++;
        }
    }
};

int main()
{
    vector<int> nums;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 20; i++)
        nums.push_back(rand() % 100);
    for (auto num : nums)
        cout << num << " ";
    SelectSort().sort(nums);
    cout << endl;
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}