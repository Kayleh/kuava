
using namespace std;

#include <bits/stdc++.h>

class Trie {
private :
    vector<Trie *> children;
    bool isEnd;

    /** Returns if there is any word in the trie that starts with the given prefix. */
    Trie *searchPrefix(string prefix) {
        Trie *node = this;
        for (char c: prefix) {
            c -= 'a';
            if (node->children[c] == nullptr) {
                return nullptr;
            }
            node = node->children[c];
        }
        return node;
    }

public:
    /** Initialize your data structure here. */
    Trie() : children(26), isEnd(false) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this; // 从根节点开始
        for (char c: word) {
            c -= 'a';
            if (!node->children[c]) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};
