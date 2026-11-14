#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node { int value; Node* left; Node* right; Node(int v): value(v), left(nullptr), right(nullptr) {} };

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<Node*> q; q.push(root);
    while (!q.empty()) {
        int size = (int)q.size();
        vector<int> level;
        for (int i = 0; i < size; i++) {
            Node* node = q.front(); q.pop();
            level.push_back(node->value);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

int main() {
    Node* root = new Node(1); root->left = new Node(2); root->right = new Node(3); root->left->left = new Node(4); root->left->right = new Node(5);
    auto result = levelOrder(root);
    for (const auto& level : result) { for (int x : level) cout << x << " "; cout << endl; }
    return 0;
}
