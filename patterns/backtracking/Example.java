import java.util.*;

public class Example {
    public static List<List<Integer>> subsetSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        dfs(nums, 0, new ArrayList<>(), target, result);
        return result;
    }

    private static void dfs(int[] nums, int start, List<Integer> path, int remaining, List<List<Integer>> result) {
        if (remaining == 0) { result.add(new ArrayList<>(path)); return; }
        for (int i = start; i < nums.length; i++) {
            if (nums[i] > remaining) break;
            path.add(nums[i]);
            dfs(nums, i + 1, path, remaining - nums[i], result);
            path.remove(path.size() - 1);
        }
    }

    public static void main(String[] args) { System.out.println(subsetSum(new int[]{1, 2, 3, 4}, 5)); }
}
