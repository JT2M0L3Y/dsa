class Node {
    int value; Node next;
    Node(int value) { this.value = value; }
}

public class Example {
    public static Node reverseList(Node head) {
        Node prev = null, current = head;
        while (current != null) {
            Node next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    public static void main(String[] args) {
        Node a = new Node(1), b = new Node(2), c = new Node(3);
        a.next = b; b.next = c;
        Node head = reverseList(a);
        while (head != null) { System.out.print(head.value + " "); head = head.next; }
    }
}
