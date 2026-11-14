import java.util.*;

public class Example {
    public static int countIslands(char[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        int count = 0;
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int r = 0; r < rows; r++) { for (int c = 0; c < cols; c++) { if (grid[r][c] == '1' && !visited[r][c]) { count++; Queue<int[]> q = new ArrayDeque<>(); q.offer(new int[]{r, c}); visited[r][c] = true; while (!q.isEmpty()) { int[] cell = q.poll(); for (int[] d : dirs) { int nr = cell[0] + d[0], nc = cell[1] + d[1]; if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1' && !visited[nr][nc]) { visited[nr][nc] = true; q.offer(new int[]{nr, nc}); } } } } } } return count;
    }

    public static void main(String[] args) { char[][] grid = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}}; System.out.println(countIslands(grid)); }
}
