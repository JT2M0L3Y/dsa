import java.util.*;

public class Example {
    public static Map<Character, Integer> dijkstra(Map<Character, List<int[]>> graph, char start) {
        Map<Character, Integer> dist = new HashMap<>();
        for (char c : graph.keySet()) dist.put(c, Integer.MAX_VALUE);
        dist.put(start, 0);
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[]{0, start});
        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            char node = (char) current[1];
            if (current[0] > dist.get(node)) continue;
            for (int[] edge : graph.get(node)) {
                char next = (char) edge[0];
                int newCost = current[0] + edge[1];
                if (newCost < dist.get(next)) { dist.put(next, newCost); pq.offer(new int[]{newCost, next}); }
            }
        }
        return dist;
    }

    public static void main(String[] args) {
        Map<Character, List<int[]>> graph = new HashMap<>();
        graph.put('A', List.of(new int[]{'B', 2}, new int[]{'C', 5}));
        graph.put('B', List.of(new int[]{'C', 1}, new int[]{'D', 4}));
        graph.put('C', List.of(new int[]{'D', 1}));
        graph.put('D', List.of());
        System.out.println(dijkstra(graph, 'A'));
    }
}
