public class Example {
    public static int singleNumber(int[] nums) {
        int result = 0;
        for (int x : nums) result ^= x;
        return result;
    }

    public static void main(String[] args) { System.out.println(singleNumber(new int[]{2, 2, 3, 3, 5})); }
}
