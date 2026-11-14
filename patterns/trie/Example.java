import java.util.*;

public class Example {
    static class TrieNode { Map<Character, TrieNode> children = new HashMap<>(); boolean isEnd = false; }
    static class Trie {
        TrieNode root = new TrieNode();
        void insert(String word) { TrieNode node = root; for (char ch : word.toCharArray()) { node.children.putIfAbsent(ch, new TrieNode()); node = node.children.get(ch); } node.isEnd = true; }
        boolean contains(String word) { TrieNode node = root; for (char ch : word.toCharArray()) { if (!node.children.containsKey(ch)) return false; node = node.children.get(ch); } return node.isEnd; }
    }
    public static void main(String[] args) { Trie trie = new Trie(); trie.insert("apple"); trie.insert("app"); trie.insert("banana"); System.out.println(trie.contains("app")); }
}
