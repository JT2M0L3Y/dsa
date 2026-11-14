import java.util.*;

public class Example {
    public static List<int[]> activitySelection(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[1]));
        List<int[]> chosen = new ArrayList<>();
        int lastEnd = -1;
        for (int[] interval : intervals) {
            if (interval[0] >= lastEnd) { chosen.add(interval); lastEnd = interval[1]; }
        }
        return chosen;
    }

    public static void main(String[] args) {
        int[][] intervals = {{1, 3}, {2, 4}, {3, 5}, {5, 7}};
        System.out.println(activitySelection(intervals));
    }
}
