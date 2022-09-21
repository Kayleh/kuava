package template.Java.b搜索;

import java.util.*;

/**
 * 基于已有的信息对搜索的每一个分支选择都做估价，进而选择分支。
 * 简单来说，启发式搜索就是对取和不取都做分析，从中选取更优解或删去无效解。
 * <p>
 * 最佳优先搜索的估价函数是 h（当前状态到目标状态的预估代价）；
 * A* 搜索的估价函数是 g+h（当前状态已消耗的代价+当前状态到目标状态的预估代价）。
 * 因此可以这样感性地解释：最佳优先搜索是为了快速找到一个解，而 A* 是为了快速找到一个最优解。
 */
public class 启发式搜索AStar {

}

/**
 * 若不考虑 bank 的限制，对于一个特定状态而言，我们可以任意选择一位替换为 44 类字符之一，因此对于任意状态 xx 而言，
 * 其与目标状态 TT 的「理论最小转换步数」为两者对应位置不同字符的数量，而由于存在 bank 限制，
 * 实际最小步数必然满足「大于等于」该理论最小转换步数。
 * <p>
 * 基于此，我们可以计算当前状态到目标状态的「理论最小转换步数」作为启发式函数，进行启发式搜索。
 * <p>
 * 具体的，我们使用优先队列（堆）维护所有的状态，每次优先「启发值 = 理论最小转换步数」的状态进行优先出队拓展。
 */
class Solution启发式搜索 {
    class Node {
        String s;
        int val;

        Node(String _s) {
            s = _s;
            for (int i = 0; i < 8; i++) {
                if (s.charAt(i) != T.charAt(i)) val++;
            }
        }
    }

    static char[] items = new char[]{'A', 'C', 'G', 'T'};
    String S, T;

    public int minMutation(String start, String end, String[] bank) {
        Set<String> set = new HashSet<>();
        for (String s : bank) set.add(s);
        S = start;
        T = end;
        PriorityQueue<Node> q = new PriorityQueue<>((a, b) -> a.val - b.val);
        Map<String, Integer> map = new HashMap<>();
        q.add(new Node(S));
        map.put(S, 0);
        while (!q.isEmpty()) {
            Node node = q.poll();
            char[] cs = node.s.toCharArray();
            int step = map.get(node.s);
            for (int i = 0; i < 8; i++) {
                for (char c : items) {
                    if (cs[i] == c) continue;
                    char[] clone = cs.clone();
                    clone[i] = c;
                    String sub = String.valueOf(clone);
                    if (!set.contains(sub)) continue;
                    if (sub.equals(T)) return step + 1;
                    if (!map.containsKey(sub) || map.get(sub) > step + 1) {
                        map.put(sub, step + 1);
                        q.add(new Node(sub));
                    }
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        PriorityQueue<Integer> q = new PriorityQueue<>((a, b) -> a - b);
        q.add(1);
        q.add(5);
        q.add(3);
        q.add(2);
        while (!q.isEmpty()) {
            System.out.println(q.poll());
        }
    }
}

