class Node:
    def __init__(self, value, nxt=None):
        self.value = value
        self.next = nxt

def has_cycle(head):
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow is fast:
            return True
    return False

if __name__ == "__main__":
    a = Node(1)
    b = Node(2)
    c = Node(3)
    a.next = b; b.next = c; c.next = b
    print(has_cycle(a))
