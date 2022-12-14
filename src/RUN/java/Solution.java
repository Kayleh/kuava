import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public int numMatchingSubseq(String s, String[] words) {
        Map<Character, List<Integer>> map = new HashMap<>(); // 使用map存储每个字符的位置
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            map.computeIfAbsent(c, k -> new ArrayList<>()).add(i);//相当于 map.getOrDefault(c, new ArrayList<>()).add(i);
        }
        int count = 0;
        for (String word : words) { // 遍历每个单词,判断是否是子序列
            boolean ok = true;
            int m = word.length(), idx = -1; // idx表示上一个字符的位置
            for (int i = 0; i < m && ok; i++) { // 遍历单词的每个字符
                List<Integer> list = map.computeIfAbsent(word.charAt(i), k -> new ArrayList<>()); // 获取字符的位置列表
                int l = 0, r = list.size() - 1;
                while (l < r) { // 二分查找,找到第一个大于idx的位置
                    //int mid = l + r >> 1;
                    int mid = (l + r) >>> 1; // 表示无符号右移,不会出现负数，等价 l + (r - l) / 2
                    if (list.get(mid) > idx) r = mid;
                    else l = mid + 1;
                }
                if (r < 0 || list.get(r) <= idx) ok = false; // 不存在大于idx的位置,说明不是子序列
                else idx = list.get(r);
            }
            if (ok) count++;
        }
        return count;
    }
}