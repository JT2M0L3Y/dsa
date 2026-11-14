class Node {
    int value; Node left, right;
    Node(int value) { this.value = value; }
}

public class Example {
    public static int maxDepth(Node root) {
        if (root == null) return 0;
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }

    public static void main(String[] args) {
        Node root = new Node(1); root.left = new Node(2); root.right = new Node(3);
        root.left.left = new Node(4); root.left.right = new Node(5);
        System.out.println(maxDepth(root));
    }
}
