class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def max_depth(root):
    if not root:
        return 0
    return 1 + max(max_depth(root.left), max_depth(root.right))

if __name__ == "__main__":
    root = Node(1, Node(2, Node(4), Node(5)), Node(3))
    print(max_depth(root))
