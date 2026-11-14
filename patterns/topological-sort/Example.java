import java.util.*;

public class Example {
    public static List<Integer> topologicalSort(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph = new ArrayList<>();
        int[] indegree = new int[numCourses];
        for (int i = 0; i < numCourses; i++) graph.add(new ArrayList<>());
        for (int[] edge : prerequisites) {
            graph.get(edge[1]).add(edge[0]);
            indegree[edge[0]]++;
        }
        Queue<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < numCourses; i++) { if (indegree[i] == 0) queue.offer(i); }
        List<Integer> order = new ArrayList<>();
        while (!queue.isEmpty()) {
            int course = queue.poll();
            order.add(course);
            for (int nxt : graph.get(course)) {
                indegree[nxt]--;
                if (indegree[nxt] == 0) queue.offer(nxt);
            }
        }
        return order;
    }

    public static void main(String[] args) {
        int[][] prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
        System.out.println(topologicalSort(4, prerequisites));
    }
}
