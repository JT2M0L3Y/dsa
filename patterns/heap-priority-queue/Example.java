import java.util.*;

public class Example {
    public static List<Integer> topKLargest(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int x : nums) {
            minHeap.offer(x);
            if (minHeap.size() > k) minHeap.poll();
        }
        return new ArrayList<>(minHeap);
    }

    public static void main(String[] args) {
        int[] nums = {3, 2, 1, 5, 4};
        System.out.println(topKLargest(nums, 3));
    }
}
