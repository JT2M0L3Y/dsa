public class Example {
    static class SegmentTree {
        int[] tree; int n;
        SegmentTree(int[] nums) { n = nums.length; tree = new int[2 * n]; System.arraycopy(nums, 0, tree, n, n); for (int i = n - 1; i > 0; i--) tree[i] = tree[2 * i] + tree[2 * i + 1]; }
        void update(int index, int value) { int pos = n + index; tree[pos] = value; pos /= 2; while (pos > 0) { tree[pos] = tree[2 * pos] + tree[2 * pos + 1]; pos /= 2; } }
        int query(int left, int right) { left += n; right += n; int sum = 0; while (left <= right) { if ((left & 1) == 1) sum += tree[left++]; if ((right & 1) == 0) sum += tree[right--]; left /= 2; right /= 2; } return sum; }
    }

    public static void main(String[] args) { SegmentTree st = new SegmentTree(new int[]{1, 2, 3, 4, 5}); System.out.println(st.query(1, 3)); st.update(2, 10); System.out.println(st.query(1, 3)); }
}
