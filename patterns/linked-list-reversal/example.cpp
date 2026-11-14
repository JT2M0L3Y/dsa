#include <iostream>
using namespace std;

struct Node { int value; Node* next; Node(int v) : value(v), next(nullptr) {} };

Node* reverseList(Node* head) {
    Node* prev = nullptr, *current = head;
    while (current) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    Node* a = new Node(1), *b = new Node(2), *c = new Node(3);
    a->next = b; b->next = c;
    Node* head = reverseList(a);
    while (head) { cout << head->value << " "; head = head->next; }
    cout << endl;
    return 0;
}
