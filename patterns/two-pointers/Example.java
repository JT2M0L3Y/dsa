public class Example {
    public static int[] pairSumTarget(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int current = nums[left] + nums[right];
            if (current == target) return new int[] {left, right};
            if (current < target) left++;
            else right--;
        }
        return null;
    }

    public static void main(String[] args) {
        int[] nums = {1, 3, 4, 7, 10, 12};
        int[] result = pairSumTarget(nums, 11);
        if (result != null) System.out.println(result[0] + ", " + result[1]);
    }
}
