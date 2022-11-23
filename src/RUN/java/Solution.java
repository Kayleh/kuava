import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int maxmiumScore(int[] cards, int cnt) {
        Arrays.sort(cards);
        //奇偶分开, 求前缀和
        List<Integer> odd = new ArrayList<>();
        List<Integer> even = new ArrayList<>(); //偶数的前缀和
        for (int i = cards.length - 1; i >= 0; i--) {
            int e = cards[i];
            if ((e & 1) == 0) {
                even.add(even.isEmpty() ? e : even.get(even.size() - 1) + e);
            } else {
                odd.add(odd.isEmpty() ? e : odd.get(odd.size() - 1) + e);
            }
        }

        int ans = 0;
        //设奇数个数为x(必须是偶数), 偶数个数为cnt-x
        //从原序列中取出偶数个奇数（偶数个奇数的和为偶数）
        for (int x = 0; x <= odd.size(); x += 2) {
            //从原序列中取出偶数个偶数（偶数个偶数的和为偶数）
            int j = cnt - x;
            if (0 <= j && j <= even.size()) {
                int i = x == 0 ? 0 : odd.get(x - 1); //奇数的和
                int i1 = j == 0 ? 0 : even.get(j - 1); //偶数的和
                ans = Math.max(ans, i + i1);
            }
        }
        return ans;
    }
}