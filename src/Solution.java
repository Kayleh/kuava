/*
 *  $ codeforce  2022-08-20
 *
 *  Copyright 2022  Kayleh. All rights reserved.
 *  @see {@link https://github.com/Kayleh/kuava}
 *
 */

import java.util.Stack;

class Solution {
    public String smallestNumber(String pattern) {
        Stack<Integer> stack = new Stack<>();
        StringBuilder res = new StringBuilder();
        int num = 1;

        for (int i = 0; i < pattern.length(); i++) {
            if (pattern.charAt(i) == 'D') {
                // 如果为下降，则将当前数字压入栈中
                stack.push(num);
            } else if (pattern.charAt(i) == 'I') {
                res.append(num);
                while (!stack.isEmpty()) {
                    res.append(stack.pop());
                }
            }
            num++;
        }

        stack.add(num);
        while (!stack.isEmpty()) {
            res.append(stack.pop());
        }
        return res.toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.smallestNumber("DID"));
    }
}

