import java.util.*;

public class Example {
    public static int[] nextGreater(int[] nums) {
        int[] result = new int[nums.length]; Arrays.fill(result, -1);
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = nums.length - 1; i >= 0; i--) {
            while (!stack.isEmpty() && stack.peek() <= nums[i]) stack.pop();
            if (!stack.isEmpty()) result[i] = stack.peek();
            stack.push(nums[i]);
        }
        return result;
    }

    public static void main(String[] args) { System.out.println(Arrays.toString(nextGreater(new int[]{2, 1, 3, 5, 4}))); }
}
