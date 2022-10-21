#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        // 二分查找
        // 如果中间值大于最右边的值，说明最小值在右边，否则在左边

        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }
};

int main() {
    Solution solution;
    vector<int> startTime = vector<int>();
    solution.findMin(startTime, startTime, startTime);
    return 0;
}