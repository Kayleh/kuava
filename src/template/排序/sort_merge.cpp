using namespace std;
#include <bits/stdc++.h>

/**
 * 归并排序
 * @brief 将每个元素看成一个长度为1的有序序列，然后两两合并，直到合并成一个长度为n的有序序列
 * @时间复杂度 O(nlogn)
 * @空间复杂度 O(n)
 */
class mergeSort
{
public:
    void sort(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> tmp(n);
        mergeSorting(nums, 0, n - 1, tmp);
    }

    /**
     * 将数组拆分成两个部分，分别进行归并排序
     */
    void mergeSorting(vector<int> &nums, int l, int r, vector<int> &tmp)
    {
        if (l >= r)
            return;
        int mid = (l + r) >> 1;
        mergeSorting(nums, l, mid, tmp);
        mergeSorting(nums, mid + 1, r, tmp);
        merge(nums, l, mid, r, tmp);
    }

    /**
     * 将两个有序数组合并成一个有序数组
     */
    void merge(vector<int> &nums, int l, int mid, int r, vector<int> &tmp)
    {
        int i = l, j = mid + 1, k = l; // i指向左半部分的起始位置，j指向右半部分的起始位置，k指向临时数组的起始位置
        while (i <= mid && j <= r)
        {
            // 两个数组都还有元素，比较两个数组的当前元素，将较小的放入临时数组
            if (nums[i] <= nums[j])
                tmp[k++] = nums[i++];
            else
                tmp[k++] = nums[j++];
        }
        while (i <= mid) // 左半部分还有元素，将剩余元素放入临时数组
            tmp[k++] = nums[i++];
        while (j <= r) // 右半部分还有元素，将剩余元素放入临时数组
            tmp[k++] = nums[j++];
        for (int i = l; i <= r; i++) // 将临时数组的元素复制回原数组
            nums[i] = tmp[i];
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