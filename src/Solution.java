import java.util.PriorityQueue;

class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        // 每次选择前candidates个和后candidates个costs最小的
        // 选择k次


        PriorityQueue<Integer> front = new PriorityQueue<>();
        PriorityQueue<Integer> end = new PriorityQueue<>();

        long ans = 0;
        for (int i = 0; i < candidates; i++) {
            front.add(costs[i]);
            end.add(costs[costs.length - 1 - i]);
        }

        int left = candidates - 1;
        int right = costs.length - candidates;
        System.out.println("left: " + left + " right: " + right);
        for (int i = 0; i < k; i++) {
            Integer f = front.peek(); // 前面的最小值
            Integer e = end.peek(); // 后面的最小值

            System.out.println("front: " + front + " end: " + end);
            // 比较两者中较小的，选择较小的，并弹出，然后补充新的
            if (f != null && e != null) { // 两者都不为空
                if (f <= e) {
                    ans += f;
                    System.out.println("选择1 前面的" + f);
                    front.poll();
                    if (left < right) {
                        front.add(costs[++left]); // 补充新的
                    }
                } else {
                    ans += e; // 选择后candidates个
                    end.poll();
                    System.out.println("选择2 后面的" + e);
                    if (right > 0 && right > left) {
                        end.add(costs[--right]);
                    }
                }
            } else {
                if (f != null) {
                    ans += f;
                    System.out.println("选择3 前面的" + f);
                    front.poll();
                    if (left < right) {
                        front.add(costs[++left]);
                    }
                } else if (e != null) {
                    ans += e;
                    System.out.println("选择4 后面的" + e);
                    end.poll();
                    if (right > 0 && right > left) {
                        end.add(costs[--right]);
                    }
                }
            }
            while (front.size() < candidates) {
                if (end.isEmpty()) {
                    break;
                }
                Integer poll = end.poll();
                if (poll != null) {
                    front.add(poll);
                }
            }
        }

        return ans;
    }
}