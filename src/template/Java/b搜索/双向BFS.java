package template.Java.b搜索;

import java.util.*;

public class 双向BFS {
}


/**
 * 双向BFS
 */
class Solution {
    static char[] items = new char[]{'A', 'C', 'G', 'T'};
    Set<String> set = new HashSet<>();

    /**
     * 求S变成T最短路径
     *
     * @param S    开始的字符串
     * @param T    目标字符串
     * @param bank 可以变换的字符串
     * @return
     */
    public int minMutation(String S, String T, String[] bank) {
        set.add(S);
        set.addAll(Arrays.asList(bank));
        if (!set.contains(T)) return -1;
        Deque<String> startDeque = new ArrayDeque<>(), endDeque = new ArrayDeque<>();
        startDeque.addLast(S);
        endDeque.addLast(T);
        Map<String, Integer> m1 = new HashMap<>(), m2 = new HashMap<>();
        m1.put(S, 0);
        m2.put(T, 0);
        while (!startDeque.isEmpty() && !endDeque.isEmpty()) {
            int t = -1;
            if (startDeque.size() <= endDeque.size()) t = update(startDeque, m1, m2);
            else t = update(endDeque, m2, m1);
            if (t != -1) return t;
        }
        return -1;
    }

    int update(Deque<String> d, Map<String, Integer> cur, Map<String, Integer> other) {
        int m = d.size();
        while (m-- > 0) {
            String s = d.pollFirst();
            char[] cs = s.toCharArray();
            int step = cur.get(s);
            for (int i = 0; i < 8; i++) {
                for (char c : items) {
                    if (cs[i] == c) continue;
                    char[] clone = cs.clone();
                    clone[i] = c;
                    String sub = String.valueOf(clone);
                    if (!set.contains(sub) || cur.containsKey(sub)) continue;
                    if (other.containsKey(sub)) return other.get(sub) + step + 1;
                    d.addLast(sub);
                    cur.put(sub, step + 1);
                }
            }
        }
        return -1;
    }
}



