import java.util.Arrays;

/**
 * 远征队在出发前需要携带一些「符文」，作为后续的冒险储备。runes[i] 表示第 i 枚符文的魔力值。
 * <p>
 * 他们将从中选取若干符文进行携带，并对这些符文进行重新排列，以确保任意相邻的两块符文之间的魔力值相差不超过 1。
 * <p>
 * 请返回他们能够携带的符文 最大数量。
 */
class Solution {
    public int runeReserve(int[] runes) {
        Arrays.sort(runes);
        int max = 0;    // 最大符文数量
        int cur = 0; // 当前符文数量
        int l = 0, r = 0;
        // 滑动窗口
        while (r < runes.length) {
            if (runes[r] - runes[l] <= 1) {
                cur++;
                max = Math.max(max, cur);
                r++;
            } else {
                cur--;
                l++;
                if (cur < 0) {
                    cur = 0;
                    l = r; // 重置窗口
                }

            }
        }
        return max;
    }
}