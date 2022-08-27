/*
 *  $ codeforce  2022-08-27
 *
 *  Copyright 2022  Kayleh. All rights reserved.
 *  @see {@link https://github.com/Kayleh/kuava}
 *
 */
package template.Java.a1算法基础;

import java.util.*;

public class tmp_BFS搜索 {
    /**
     * 待搜索的状态枚举
     */
    static char[] items = new char[]{'A', 'C', 'G', 'T'};

    public int BFS(String START, String END, String[] bank) {
        Set<String> bankMap = new HashSet<>(Arrays.asList(bank));
        Deque<String> deque = new ArrayDeque<>();
        Map<String, Integer> map = new HashMap<>();
        deque.addLast(START);
        map.put(START, 0);
        while (!deque.isEmpty()) {//如果新状态合法并且没有在记录步数的哈希表中出现过，则将新状态入队并更新得到新状态所用步数，否则丢弃新状态。
            int size = deque.size();
            while (size-- > 0) {
                String s = deque.pollFirst();
                char[] cs = s.toCharArray();
                int step = map.get(s);
                for (int i = 0; i < 8; i++) { //遍历每一位基因
                    for (char c : items) {  //当前基因的可变枚举
                        if (cs[i] == c) continue;//跳过重复的枚举
                        char[] clone = cs.clone();
                        clone[i] = c;
                        String sub = String.valueOf(clone);
                        if (!bankMap.contains(sub)) continue; //新状态合法
                        if (map.containsKey(sub)) continue;//没有在记录步数的哈希表中出现过
                        if (sub.equals(END)) return step + 1;
                        map.put(sub, step + 1);//更新得到新状态所用步数
                        deque.addLast(sub);//将新状态入队
                    }
                }
            }
        }
        return -1;
    }
}
