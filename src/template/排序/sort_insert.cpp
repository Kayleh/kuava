using namespace std;
#include <bits/stdc++.h>

/**
 * 插入排序
 * @brief  每次从未排序的部分选择一个元素，插入到已排序的部分的合适位置
 * @时间复杂度  O(n^2)
 * @空间复杂度  O(1)
 */
class insertSort
{
public:
    void sort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            int cur = nums[i]; // 当前要插入的元素
            int j = i - 1;     // 已排序的部分的末尾
            while (j >= 0 && nums[j] > cur)
            {
                nums[j + 1] = nums[j]; // 向后移动
                j--;                   // 继续向前比较
            }
            nums[j + 1] = cur;
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
    insertSort().sort(nums);
    cout << endl;
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}