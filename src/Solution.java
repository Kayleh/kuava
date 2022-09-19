class Solution {
    public int[] sumPrefixScores(String[] words) {
        Trie trie = new Trie();
        for (String word : words) {
            trie.insert(word);
        }
        int[] ans = new int[words.length];
        for (int i = 0; i < words.length; i++) {
            ans[i] = trie.sumPrefixScore(words[i]);
        }

        return ans;
    }
}

class Trie {


    TrieNode root; // 根节点

    /**
     * Initialize your data structure here.
     */
    public Trie() {
        root = new TrieNode();
    }

    /**
     * Inserts a word into the trie.
     */
    public void insert(String s) {
        TrieNode p = root; // 从根节点开始
        for (int i = 0; i < s.length(); i++) {
            int u = s.charAt(i) - 'a';
            if (p.next[u] == null) p.next[u] = new TrieNode(); // 如果没有这个字符，就新建一个节点
            p = p.next[u]; // 移动到下一个节点
            p.num++;
        }
        p.end = true;
    }

    /**
     * Returns if the word is in the trie.
     */
    public boolean search(String s) {
        TrieNode p = root;
        for (int i = 0; i < s.length(); i++) {
            int u = s.charAt(i) - 'a';
            if (p.next[u] == null) return false; // 如果没有这个字符，就返回 false
            p = p.next[u]; // 移动到下一个节点
        }
        return p.end;
    }

    /**
     * 返回是否存在某个字符串的前缀
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String s) {
        TrieNode p = root;
        for (int i = 0; i < s.length(); i++) {
            int u = s.charAt(i) - 'a';
            if (p.next[u] == null) return false;
            p = p.next[u];
        }
        return true;
    }

    public int sumPrefixScore(String s) {
        TrieNode p = root;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int u = s.charAt(i) - 'a';
            if (p.next[u] == null) return 0;
            p = p.next[u];
            ans += p.num;
        }
        return ans;
    }
}

class TrieNode {
    boolean end; // 是否为单词结尾
    TrieNode[] next = new TrieNode[26]; // 后续字符串的字符是什么
    int num; // 以该节点为前缀的单词数量
}