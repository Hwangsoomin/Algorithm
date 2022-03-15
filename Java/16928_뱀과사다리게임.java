import java.util.*;
import java.io.*;

public class Main {
    public static int n, m, x, y;
    public static int []dice = {1,2,3,4,5,6};
    public static int []arr = new int[101];
    public static int []check = new int[101];
    public static HashMap<Integer, Integer> hashMap = new HashMap<>();
    public static class Node {
        int here;
        int cost;
        Node(int here, int cost) {
            this.here = here;
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
        pq.add(new Node(1, 0));
        check[1] = 0;
         while(!pq.isEmpty()) {
             Node node = pq.poll();
             if(node.cost < check[node.here]) continue;
             for(int i=0; i<6; i++) {
                 int next = node.here + dice[i];
                 if(next > 100) continue;
                 if(arr[next] == 1) {
                     next = hashMap.get(next);
                 }
                 if(check[next] > check[node.here] + 1) {
                     check[next] = check[node.here] + 1;
                     pq.add(new Node(next, check[next]));
                 }
             }
         }
    }
    public static void main(String[] args) throws  IOException {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        for(int i=1; i<=100; i++) {
            check[i] = Integer.MAX_VALUE;
        }
        for(int i=1; i<=n+m; i++) {
            x = sc.nextInt();
            y = sc.nextInt();
            hashMap.put(x, y);
            arr[x] = 1;
        }

        bfs();
        System.out.println(check[100]);
    }
}
