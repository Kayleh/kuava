import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Long> maximumEvenSplit(long finalSum) {
        List<Long> ans = new ArrayList<>();
        if ((finalSum & 1) == 0) {
            long k = 2;
            while (true) {
                if (finalSum == k) {
                    ans.add(k);
                    break;
                } else if (finalSum < k) {
                    ans.add(ans.remove(ans.size() - 1) + finalSum);
                    break;
                } else {
                    ans.add(k);
                    finalSum -= k;
                    k += 2;
                }
            }
        }
        return ans;
    }
}