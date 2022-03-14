import java.util.*;
import java.io.*;

public class Main {
    public static int n;
    public static int []dr = {-1, 0, 1, 0};
    public static int []dc = {0, 1, 0, -1};
    public static int [][]map;
    public static int [][]check;
    public static class Node {
        int x;
        int y;
        int cost;
        Node(int x, int y, int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }
    }
    public static void bfs() {
        PriorityQueue<Node> pq = new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.cost >= o2.cost ? 1 : -1;
            }
        });
        pq.add(new Node(1, 1, 0));
        check[1][1] = 0;
        while(!pq.isEmpty()) {
            Node here = pq.poll();
            int r = here.x;
            int c = here.y;
            if(check[r][c] < here.cost) continue;
            for(int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<1 || nr>n || nc<1 || nc>n) continue;
                if(map[nr][nc]==1){
                    if(check[nr][nc] > check[r][c]) {
                        check[nr][nc] = check[r][c];
                        pq.add(new Node(nr, nc, check[nr][nc]));
                    }
                }
                else {
                    if(check[nr][nc] > check[r][c] + 1) {
                        check[nr][nc] = check[r][c] + 1;
                        pq.add(new Node(nr, nc, check[nr][nc]));
                    }
                }
            }
        }
    }
    public static void main(String[] args) throws  IOException {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        map = new int[n+1][n+1];
        check = new int[n+1][n+1];
        for(int i=1; i<=n; i++) {
            String []str = sc.next().split("");
            for(int j=0; j<n; j++) {
                map[i][j+1] = Integer.parseInt(str[j]);
                check[i][j+1] = Integer.MAX_VALUE;
            }
        }
        bfs();
        System.out.println(check[n][n]);
    }
}
