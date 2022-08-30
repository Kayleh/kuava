import java.util.HashMap;
import java.util.Map;
import java.util.Set;

class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        // 键:垃圾 值:垃圾最后出现的位置和垃圾的数量
        Map<String, Object[]> map = new HashMap<>();
        for (int j = 0; j < garbage.length; j++) {
            char[] chars = garbage[j].toCharArray();
            for (char c : chars) {
                String key = "" + c;
                Object[] objects = map.getOrDefault(key, new Object[]{0, 0});
                int count = (int) objects[1];
                objects[0] = j;// 垃圾最后出现的位置
                objects[1] = count + 1;// 垃圾的数量
                map.put(key, objects);
            }
        }

        // 前缀和数组: 垃圾车到达该位置所需时间
        int[] preSum = new int[travel.length + 1];
        preSum[0] = 0;
        for (int i = 1; i < preSum.length; i++) {
            preSum[i] = preSum[i - 1] + travel[i - 1];
        }

        int times = 0;
        Set<Map.Entry<String, Object[]>> entries = map.entrySet();
        for (Map.Entry<String, Object[]> entry : entries) {
            Object[] objects = entry.getValue();
            int count = (int) objects[1];// 垃圾的数量
            int lastStrIndex = (int) objects[0];// 垃圾最后出现的位置
            // 清理垃圾的时间 = 垃圾车到达垃圾最后出现的位置所需的时间 + 垃圾的数量（清理垃圾的时间）
            times += preSum[lastStrIndex] + count;
        }
        return times;

    }
}

