#include <iostream>
using namespace std;
int main()
{
    /* code */

    /**
     * @brief 枚举
     *
     * 基于已有知识来猜测答案的一种问题求解策略。
     * 枚举的思想是不断地猜测，从可能的集合中一一尝试，然后再判断题目的条件是否成立。
     *
     * e.g.一个数组中的数互不相同，求其中和为 0 的数对的个数。
     */
    int a[] = {1, 2, -1, -2, 5};
    // sizeof(a) 是数组占用内存的大小，也是数组的长度。
    // sizeof(a[0])是数组中每个元素占用的内存大小。
    // sizeof(a) / sizeof(a[0]) 是数组的元素的个数。
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == 0)
                cout << a[i] << " " << a[j] << endl;
        }
    }
    return 0;
}
