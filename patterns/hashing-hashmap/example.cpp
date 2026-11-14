#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> countFrequencies(const vector<string>& words) { unordered_map<string, int> freq; for (const string& word : words) freq[word]++; return freq; }

int main() { vector<string> words = {"apple", "banana", "apple", "cherry"}; auto freq = countFrequencies(words); for (const auto& entry : freq) cout << entry.first << ": " << entry.second << endl; return 0; }
