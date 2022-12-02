import java.util.Arrays;

class Solution {

    public int purchasePlans(int[] nums, int target) {
        int cnt = 0;
        // 思路：排序后，双指针，左指针从左往右，右指针从右往左，如果左右指针指向的数之和大于target，右指针左移，否则左指针右移
        Arrays.sort(nums);
        int i = 0, j = nums.length - 1;
        while (i < j) {
            if (nums[i] + nums[j] <= target) {
                cnt += j - i;
                i++;
            } else {
                j--;
            }
            cnt %= 1000000007;
        }
        return cnt % 1000000007;
    }

    private void main(String[] args) {
        int[] nums = {2, 5, 3, 5};
        int target = 6;
        System.out.println(purchasePlans(nums, target));
    }
}