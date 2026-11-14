class Node:
    def __init__(self, value, nxt=None):
        self.value = value
        self.next = nxt

def reverse_list(head):
    prev = None
    current = head
    while current:
        nxt = current.next
        current.next = prev
        prev = current
        current = nxt
    return prev

if __name__ == "__main__":
    head = Node(1, Node(2, Node(3)))
    res = reverse_list(head)
    while res:
        print(res.value, end=' ' )
        res = res.next
