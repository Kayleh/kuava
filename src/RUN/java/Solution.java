import java.util.HashSet;

class Solution {
    int maxSplit = 0;
    private HashSet<String> hashSet;

    public int maxUniqueSplit(String s) {
        hashSet = new HashSet<String>();
        dfs(s, 0);
        return maxSplit;
    }

    private void dfs(String s, int i) {
        if (i == s.length()) {
            maxSplit = Math.max(maxSplit, hashSet.size());
            return;
        }
        for (int j = i; j < s.length(); j++) {
            String sub = s.substring(i, j + 1);
            if (!hashSet.contains(sub)) {
                hashSet.add(sub);
                dfs(s, j + 1);
                hashSet.remove(sub);
            }
        }
    }
}