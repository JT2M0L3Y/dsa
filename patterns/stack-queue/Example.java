import java.util.*;

public class Example {
    public static boolean isValidParentheses(String s) { Deque<Character> stack = new ArrayDeque<>(); Map<Character, Character> pairs = Map.of(')', '(', ']', '[', '}', '{'); for (char ch : s.toCharArray()) { if (ch == '(' || ch == '[' || ch == '{') stack.push(ch); else if (stack.isEmpty() || stack.pop() != pairs.get(ch)) return false; } return stack.isEmpty(); }
    public static void main(String[] args) { System.out.println(isValidParentheses("([{}])")); }
}
