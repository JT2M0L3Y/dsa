public class Example {
    static class Fenwick {
        int[] bit; int n;
        Fenwick(int[] nums) { n = nums.length; bit = new int[n + 1]; for (int i = 0; i < n; i++) add(i, nums[i]); }
        void add(int index, int delta) { index += 1; while (index <= n) { bit[index] += delta; index += index & -index; } }
        int prefixSum(int index) { index += 1; int sum = 0; while (index > 0) { sum += bit[index]; index -= index & -index; } return sum; }
    }

    public static void main(String[] args) { Fenwick fw = new Fenwick(new int[]{1, 2, 3, 4, 5}); System.out.println(fw.prefixSum(3)); fw.add(2, 10); System.out.println(fw.prefixSum(3)); }
}
