public class Example {
    static class UnionFind {
        int[] parent, rank;
        UnionFind(int n) { parent = new int[n]; rank = new int[n]; for (int i = 0; i < n; i++) parent[i] = i; }
        int find(int x) { if (parent[x] != x) parent[x] = find(parent[x]); return parent[x]; }
        void union(int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return;
            if (rank[ra] < rank[rb]) parent[ra] = rb;
            else if (rank[ra] > rank[rb]) parent[rb] = ra;
            else { parent[rb] = ra; rank[ra]++; }
        }
    }

    public static void main(String[] args) {
        UnionFind uf = new UnionFind(5);
        uf.union(0, 1); uf.union(1, 2); uf.union(3, 4);
        System.out.println(uf.find(2));
    }
}
