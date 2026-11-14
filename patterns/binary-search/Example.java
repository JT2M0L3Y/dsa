public class Example {
    public static int firstTrue(boolean[] nums) {
        int left = 0, right = nums.length - 1, answer = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid]) { answer = mid; right = mid - 1; } else { left = mid + 1; }
        }
        return answer;
    }

    public static void main(String[] args) {
        boolean[] nums = {false, false, true, true, true};
        System.out.println(firstTrue(nums));
    }
}
