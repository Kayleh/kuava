#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /**
     * next_permutation函数
     * next_permutation函数可以求出当前排列的下一个排列，如果不存在下一个排列，则返回 false。
     * @param nums
     * @return
     */
    void test_next_permutation()
    {
        vector<int> nums = {1, 2, 3};
        do
        {
            for (auto x : nums)
                cout << x << ' ';
            cout << endl;
        } while (next_permutation(nums.begin(), nums.end()));
    }

    /**
     * iota函数
     * iota函数可以将一个区间内的值依次赋值为0,1,2,3,4,5,6,7,8,9
     * @param nums
     */
    void test_iota()
    {
        vector<int> nums(10);
        iota(nums.begin(), nums.end(), 0);
        for (auto x : nums)
            cout << x << ' ';
        cout << endl;
    }

    /**
     * accumulate函数
     * accumulate函数可以求出一个区间内的所有值的和
     * @param nums
     */
    void test_accumulate()
    {
        vector<int> nums = {1, 2, 3, 4, 5};
        cout << accumulate(nums.begin(), nums.end(), 0) << endl;
    }
};