import java.util.*;
import java.io.*;

public class Main {
    public static ArrayList<Integer> []arr;
    public static int []check;
    public static int []answer;
    public static int answerIndex = 0;
    public static void main(String[] args) throws  IOException {
        int n, m, v, a, b;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        v = sc.nextInt();
        arr = new ArrayList[n+1];
        check = new int[n+1];
        answer = new int[n+1];

        for(int i=0; i<=n; i++) {
            arr[i] = new ArrayList<>();
        }

        for(int i=1; i<=m; i++) {
            a = sc.nextInt();
            b = sc.nextInt();
            arr[a].add(b);
            arr[b].add(a);
        }

        for(int i=0; i<=n; i++) {
            Collections.sort(arr[i]);
        }

        Arrays.fill(check, 0);
        Arrays.fill(answer, 0);
        dfs(v);
        for(int i=0; i<answerIndex; i++) {
            System.out.print(answer[i] + " ");
        }
        System.out.println();
        Arrays.fill(check, 0);
        Arrays.fill(answer, 0);
        answerIndex = 0;
        bfs(v);
        for(int i=0; i<answerIndex; i++) {
            System.out.print(answer[i] + " ");
        }
    }

    public static void dfs(int here) {
        check[here] = 1;
        answer[answerIndex++] = here;
        for(int i=0; i<arr[here].size(); i++) {
            int next = arr[here].get(i);
            if(check[next]==0) {
                check[next] = 1;
                dfs(next);
            }
        }
    }
    public static void bfs(int num) {
        Queue<Integer> q = new LinkedList<>();
        q.add(num);
        while(!q.isEmpty()) {
            int here = q.poll();
            answer[answerIndex++] = here;
            check[here] = 1;
            for(int i=0; i<arr[here].size(); i++) {
                int next = arr[here].get(i);
                if(check[next]==0) {
                    check[next] = 1;
                    q.add(next);
                }
            }
        }
    }
}
