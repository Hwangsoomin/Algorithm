import java.util.*;
import java.io.*;

public class Main {
    public static int n, m, r;
    public static int []item;
    public static long [][]dist;
    public static void fl() {
        for(int k=1; k<=n; k++) {
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    if(dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
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
        dist = new long[n+1][n+1];
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i==j) dist[i][j] = 0;
                else dist[i][j] = Integer.MAX_VALUE;
            }
        }
        for(int i=1; i<=n; i++) {
            t = sc.nextInt();
            item[i] = t;
        }
        for(int i=1; i<=r; i++) {
            a = sc.nextInt();
            b = sc.nextInt();
            l = sc.nextInt();
            dist[a][b] = l;
            dist[b][a] = l;
        }
        fl();
        for(int i=1; i<=n; i++) {
            int sum = 0;
            for(int j=1; j<=n; j++) {
                if(dist[i][j] <= m) {
                    sum += item[j];
                }
            }
            answer = Math.max(answer, sum);
        }
        System.out.println(answer);
    }
}
