#include <iostream>
using namespace std;

struct Node { int value; Node* next; Node(int v) : value(v), next(nullptr) {} };

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    Node* a = new Node(1), *b = new Node(2), *c = new Node(3);
    a->next = b; b->next = c; c->next = b;
    cout << boolalpha << hasCycle(a) << endl;
    return 0;
}
