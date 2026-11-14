import java.util.*;

public class Example {
    public static int connectedComponents(int n, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        boolean[] visited = new boolean[n];
        int count = 0;
        for (int start = 0; start < n; start++) {
            if (visited[start]) continue;
            count++;
            Queue<Integer> q = new ArrayDeque<>();
            q.offer(start);
            visited[start] = true;
            while (!q.isEmpty()) {
                int node = q.poll();
                for (int nxt : graph.get(node)) {
                    if (!visited[nxt]) {
                        visited[nxt] = true;
                        q.offer(nxt);
                    }
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[][] edges = {{0, 1}, {1, 2}, {3, 4}};
        System.out.println(connectedComponents(5, edges));
    }
}
