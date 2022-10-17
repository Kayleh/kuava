import java.util.HashMap;
import java.util.Map;

class Solution {
    public int minIncrementForUnique(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        int count = 0;
        for (int num : nums) {
            while (map.get(num) > 1) {
                int next = num + 1;
                map.put(num, map.get(num) - 1);
                map.put(next, map.getOrDefault(next, 0) + 1);
                num = next;
                count++;
            }
        }

        return count;
    }
}