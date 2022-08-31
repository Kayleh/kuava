/*
 *  $ codeforce  2022-08-31
 *
 *  Copyright 2022  Kayleh. All rights reserved.
 *  @see {@link https://github.com/Kayleh/kuava}
 *
 */

package template.Java.a1算法基础.A7二分;

/**
 * 二分查找（英语：binary search），也称折半搜索（英语：half-interval search）、对数搜索（英语：logarithmic search），
 * 是用来在一个有序数组中查找某一元素的算法。
 */
public class A7二分 {
    /**
     * 二分查找
     *
     * @param arr
     * @param target
     * @return
     */
    public int binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1; // 在[left, right]的范围里寻找target
        while (left <= right) { // 当left == right时，区间[left, right]依然有效
            int mid = left + (right - left) / 2;
            if (arr[mid] == target)
                return mid;
            if (target < arr[mid])
                right = mid - 1; // target在[left, mid - 1]中
            else
                left = mid + 1; // target在[mid + 1, right]中
        }
        return -1;
    }
}
