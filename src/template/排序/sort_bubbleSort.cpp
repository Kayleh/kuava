using namespace std;
#include <bits/stdc++.h>

/**
 * 冒泡排序
 * @brief 从左到右不断交换相邻逆序的元素，在一轮的循环之后，可以让未排序的最大元素上浮到右侧，像冒泡一样
 * @时间复杂度 O(n^2)
 * @空间复杂度 O(1)
 */
class BubbleSort
{
public:
    void sort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                    flag = true;
                }
            }
            if (!flag)
                break;
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
    BubbleSort().sort(nums);
    cout << endl;
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}