package template.Java;

/**
 * Trie 树（又叫「前缀树」或「字典树」） 是一种树形数据结构，
 * 用于高效地存储和检索字符串数据集中的键。快速查询「某个字符串/字符前缀」是否存在的数据结构。
 * 其核心是使用「边」来代表有无字符，使用「点」来记录是否为「单词结尾」以及「其后续字符串的字符是什么」。
 * 这一数据结构有相当多的应用情景，例如自动补完和拼写检查。
 */
class Trie {
    class TrieNode {
        boolean end; // 是否为单词结尾
        TrieNode[] next = new TrieNode[26]; // 后续字符串的字符是什么
    }

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
}

