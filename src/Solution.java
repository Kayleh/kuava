import java.util.LinkedList;

class Solution {
    public int compress(char[] chars) {
        LinkedList<Character> res = new LinkedList<>();
        int cnt = 1;
        char prev = chars[0];

        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == prev) {
                cnt++;
            } else {
                res.add(prev);
                if (cnt > 1) {
                    for (char c : String.valueOf(cnt).toCharArray()) {
                        res.add(c);
                    }
                }
                cnt = 1;
                prev = chars[i];
            }
        }

        return res.size();
    }
}