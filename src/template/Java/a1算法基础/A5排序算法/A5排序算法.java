/*
 *  $ codeforce  2022-08-29
 *
 *  Copyright 2022  Kayleh. All rights reserved.
 *  @see {@link https://github.com/Kayleh/kuava}
 *
 */

package template.Java.a1算法基础.A5排序算法;

import java.util.Arrays;

/**
 * @brief 排序算法
 */
public class A5排序算法 {

    int arr[];

    public A5排序算法(int[] arr) {
        this.arr = arr;
    }


    /**
     * @brief 冒泡排序
     * 稳定性 冒泡排序是一种稳定的排序算法。
     * 时间复杂度
     * 在序列完全有序时，冒泡排序只需遍历一遍数组，不用执行任何交换操作，时间复杂度 O(n)。
     * 在最坏情况下，冒泡排序要执行多次交换，时间复杂度 O(n^2)
     * 平均的时间复杂度为 O(n^2)
     */
    public int[] bubbleSort() {
        int len = arr.length;
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        return arr;
    }

    /**
     * @brief 选择排序
     * 稳定性 由于 swap（交换两个元素）操作的存在，选择排序是一种不稳定的排序算法。
     * 时间复杂度 O(n^2)
     * @see <a href="https://oi-wiki.org/basic/images/selection-sort-1-animate-example.svg">...</a>
     */
    public int[] selectSort() {
        int len = arr.length;
        for (int i = 0; i < len - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < len; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        return arr;
    }


    /**
     * @brief 插入排序
     * 插入排序（英语：Insertion sort）是一种简单直观的排序算法。
     * 它的工作原理为将待排列元素划分为「已排序」和「未排序」两部分，每次从「未排序的」元素中选择一个插入到「已排序的」元素中的正确位置。
     * <p>
     * 稳定性 插入排序是一种稳定的排序算法。
     * 时间复杂度
     * 插入排序的最优时间复杂度为O(n)，在数列几乎有序时效率很高。
     * 插入排序的最坏时间复杂度和平均时间复杂度都为 O(n^2)
     * O(n^2)
     */
    public int[] insertSort() {
        int len = arr.length;
        for (int i = 1; i < len; i++) {
            int preIndex = i - 1;
            int current = arr[i];
            while (preIndex >= 0 && arr[preIndex] > current) {
                arr[preIndex + 1] = arr[preIndex];
                preIndex--;
            }
            arr[preIndex + 1] = current;
        }
        return arr;
    }


    /**
     * @brief 希尔排序
     * 稳定性 希尔排序是一种不稳定的排序算法。
     * 时间复杂度 O(n^1.3)
     */
    public int[] shellSort() {
        int len = arr.length;
        int gap = len / 2;
        while (gap > 0) {
            for (int i = gap; i < len; i++) {
                int j = i;
                int current = arr[i];
                while (j - gap >= 0 && current < arr[j - gap]) {
                    arr[j] = arr[j - gap];
                    j = j - gap;
                }
                arr[j] = current;
            }
            gap = gap / 2;
        }
        return arr;
    }


    /**
     * @brief 归并排序
     * 稳定性 归并排序是一种稳定的排序算法。
     * 时间复杂度 O(nlog2n)
     */
    public int[] mergeSort(int[] arr) {
        int len = arr.length;
        if (len <= 1) {
            return arr;
        }
        int mid = len / 2;
        int[] left = Arrays.copyOfRange(arr, 0, mid);
        int[] right = Arrays.copyOfRange(arr, mid, len);
        return merge(mergeSort(left), mergeSort(right));
    }


    private int[] merge(int[] left, int[] right) {
        int len = left.length + right.length;
        int[] result = new int[len];
        int i = 0, j = 0, k = 0;
        while (i < left.length && j < right.length) {
            if (left[i] < right[j]) {
                result[k++] = left[i++];
            } else {
                result[k++] = right[j++];
            }
        }
        while (i < left.length) {
            result[k++] = left[i++];
        }
        while (j < right.length) {
            result[k++] = right[j++];
        }
        return result;
    }


    /**
     * @brief 快速排序
     * 稳定性 快速排序是一种不稳定的排序算法。
     * 时间复杂度 O(nlog2n)
     */
    public int[] quickSort(int[] arr) {
        int len = arr.length;
        if (len <= 1) {
            return arr;
        }
        int mid = len / 2;
        int[] left = Arrays.copyOfRange(arr, 0, mid);
        int[] right = Arrays.copyOfRange(arr, mid, len);
        return merge(quickSort(left), quickSort(right));
    }

    /**
     * @brief 堆排序
     * 稳定性 堆排序是一种不稳定的排序算法。
     * 时间复杂度 O(nlog2n)
     */
    public int[] heapSort() {
        int len = arr.length;
        if (len <= 1) {
            return arr;
        }
        buildHeap();
        for (int i = len - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(0, i - 1);
        }
        return arr;
    }

    private void buildHeap() {
        int len = arr.length;
        for (int i = len / 2 - 1; i >= 0; i--) {
            heapify(i, len - 1);
        }
    }

    private void heapify(int i, int len) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left <= len && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right <= len && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(largest, len);
        }
    }


    /**
     * @brief 基数排序
     * 稳定性 基数排序是一种不稳定的排序算法。
     * 时间复杂度 O(nk)
     */

    public int[] radixSort() {
        int len = arr.length;
        if (len <= 1) {
            return arr;
        }
        int max = arr[0];
        for (int i = 1; i < len; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        int exp = 1;
        while (max / exp > 0) {
            int[] bucket = new int[10];
            for (int i = 0; i < len; i++) {
                bucket[(arr[i] / exp) % 10]++;
            }
            for (int i = 1; i < 10; i++) {
                bucket[i] += bucket[i - 1];
            }
            int[] temp = new int[len];
            for (int i = len - 1; i >= 0; i--) {
                temp[--bucket[(arr[i] / exp) % 10]] = arr[i];
            }
            for (int i = 0; i < len; i++) {
                arr[i] = temp[i];
            }
            exp *= 10;
        }
        return arr;

    }


    /**
     * @brief 计数排序
     * <p>
     * 稳定性 计数排序是一种不稳定的排序算法。
     * 时间复杂度 O(n+k)
     */
    public int[] countSort() {
        int len = arr.length;
        if (len <= 1) {
            return arr;
        }
        int max = arr[0];
        for (int i = 1; i < len; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        int[] bucket = new int[max + 1];
        for (int i = 0; i < len; i++) {
            bucket[arr[i]]++;
        }
        for (int i = 1; i < max + 1; i++) {
            bucket[i] += bucket[i - 1];
        }
        int[] temp = new int[len];
        for (int i = len - 1; i >= 0; i--) {
            temp[--bucket[arr[i]]] = arr[i];
        }
        for (int i = 0; i < len; i++) {
            arr[i] = temp[i];
        }
        return arr;
    }


    /**
     * @brief 桶排序
     * 稳定性 桶排序是一种不稳定的排序算法。
     * 时间复杂度 O(n)
     */
    public int[] bucketSort() {
        int len = arr.length;
        if (len <= 1) {
            return arr;
        }
        int max = arr[0];
        for (int i = 1; i < len; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        int[] bucket = new int[max + 1];
        for (int i = 0; i < len; i++) {
            bucket[arr[i]]++;
        }
        for (int i = 1; i < max + 1; i++) {
            bucket[i] += bucket[i - 1];
        }
        int[] temp = new int[len];
        for (int i = len - 1; i >= 0; i--) {
            temp[--bucket[arr[i]]] = arr[i];
        }
        for (int i = 0; i < len; i++) {
            arr[i] = temp[i];
        }
        return arr;
    }


    /**
     * @brief 锦标赛排序
     * 稳定性 锦标赛排序是一种不稳定的排序算法。
     * 时间复杂度 O(nlog2n)
     */
    public int[] tournamentSort() {
        int len = arr.length;
        if (len <= 1) {
            return arr;
        }
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        return arr;
    }


}
