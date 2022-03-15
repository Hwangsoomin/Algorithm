import java.util.*;
import java.io.*;

public class Main {
    public static int n, m, r;
    public static int []item;
    public static ArrayList<Node> []arr;
    public static int []dist;
    public static class Node {
        int here;
        int cost;
        Node(int here, int cost) {
            this.here = here;
            this.cost = cost;
        }
    }
    public static void di(int num) {
        PriorityQueue<Node> pq = new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.cost >= o2.cost ? 1 : -1;
            }
        });
        pq.add(new Node(num, 0));
        dist[num] = 0;
        while(!pq.isEmpty()) {
            Node node = pq.poll();
            if(dist[node.here] < node.cost) continue;
            for(int i=0; i<arr[node.here].size(); i++) {
                Node nnode = arr[node.here].get(i);
                int next = nnode.here;
                int nextCost = nnode.cost;
                if(dist[next] > dist[node.here] + nextCost) {
                    dist[next] = dist[node.here] + nextCost;
                    pq.add(new Node(next, dist[next]));
                }
            }
        }
    }
    public static void main(String[] args) throws  IOException {
        int t, a, b, l, answer=0;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        r = sc.nextInt();
        item = new int[n+1];
        dist = new int[n+1];
        arr = new ArrayList[n+1];
        for(int i=1; i<=n; i++) {
            arr[i] = new ArrayList<>();
            dist[i] = Integer.MAX_VALUE;
        }
        for(int i=1; i<=n; i++) {
            t = sc.nextInt();
            item[i] = t;
        }
        for(int i=1; i<=r; i++) {
            a = sc.nextInt();
            b = sc.nextInt();
            l = sc.nextInt();
            arr[a].add(new Node(b, l));
            arr[b].add(new Node(a, l));
        }
        for(int i=1; i<=n; i++) {
            int sum = 0;
            Arrays.fill(dist, Integer.MAX_VALUE);
            di(i);
            for(int j=1; j<=n; j++) {
                if(dist[j]<=m) sum += item[j];
            }
            answer = Math.max(answer, sum);
        }

        System.out.println(answer);
    }
}
