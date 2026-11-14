#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValidParentheses(const string& s) { stack<char> st; unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}}; for (char ch : s) { if (ch == '(' || ch == '[' || ch == '{') st.push(ch); else if (st.empty() || st.top() != pairs[ch]) return false; else st.pop(); } return st.empty(); }

int main() { cout << boolalpha << isValidParentheses("([{}])") << endl; return 0; }
