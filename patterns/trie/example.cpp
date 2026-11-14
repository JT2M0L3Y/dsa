#include <iostream>
#include <unordered_map>
using namespace std;

struct TrieNode { unordered_map<char, TrieNode*> children; bool isEnd = false; };

class Trie { public: TrieNode* root = new TrieNode(); void insert(const string& word) { TrieNode* node = root; for (char ch : word) { if (!node->children.count(ch)) node->children[ch] = new TrieNode(); node = node->children[ch]; } node->isEnd = true; } bool contains(const string& word) const { TrieNode* node = root; for (char ch : word) { if (!node->children.count(ch)) return false; node = node->children.at(ch); } return node->isEnd; } };

int main() { Trie trie; trie.insert("apple"); trie.insert("app"); trie.insert("banana"); cout << boolalpha << trie.contains("app") << endl; return 0; }
