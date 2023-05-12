using namespace std;
#include <bits/stdc++.h>

/**
 * 快速排序
 * @brief  选取一个基准元素（通常为第一个元素），将数组分成两部分，左边的元素都小于基准元素，右边的元素都大于基准元素，然后递归地对左右两部分进行快速排序
 * @时间复杂度  O(n^2)
 * @空间复杂度  O(1)
 */
class QuickSort
{
public:
    void sort(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
    }

private:
    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left >= right) // 递归终止条件
            return;
        int i = left, j = right;
        int pivot = nums[left];
        while (i < j)
        {
            while (i < j && nums[j] >= pivot) // 从右向左找第一个小于基准元素的位置
                j--;
            nums[i] = nums[j]; // 将小于基准元素的数移动到左边
            while (i < j && nums[i] <= pivot) // 从左向右找第一个大于基准元素的位置
                i++;
            nums[j] = nums[i];
        }
        nums[i] = pivot; 
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
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
    QuickSort().sort(nums);
    cout << endl;
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}