package template.哈希表;

public class HashMap {

    /**
     * 统计差异
     *
     * @param source 源数组
     * @param target 目标数组
     * @return 差异的个数
     */
    public int diffCount(int[] source, int[] target) {
        int[] meno = new int[10001];
        int ans = 0;
        for (int j : source) {
            ++meno[j];
        }
        for (int j : target) {
            --meno[j];
        }
        for (int j : meno) {
            if (j != 0) {
                ans += Math.abs(j);
            }
        }
        return ans;
    }
}
