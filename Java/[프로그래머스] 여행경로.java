import java.util.*;
import java.io.*;

public class Main {
    public static ArrayList<Node> []arrayList = new ArrayList[10005];
    public static int [][]check = new int[10005][10005];
    public static String []answer = {};
    public static int answerCnt;
    public static HashMap<Integer, String> map = new HashMap<>();
    public static class Node {
        int num;
        String location;
        Node(int num, String location) {
            this.num = num;
            this.location = location;
        }
    }
    public static int dfs(int here, String location, int cnt, int allCnt) {
        if(cnt == allCnt) {
            return 1;
        }
        for(int i=0; i<arrayList[here].size(); i++) {
            Node next = arrayList[here].get(i);
            if(check[here][next.num]>0) {
                check[here][next.num] -= 1;
                if(dfs(next.num, next.location, cnt+1, allCnt)==1) {
                    answer[answerCnt--] = map.get(next.num);
                    return 1;
                }
                check[here][next.num] += 1;
            }
        }
        return 0;
    }
    public static void main(String[] args) throws  IOException {
        String [][]tickets = {{"ICN", "A"}, {"ICN", "A"}, {"A", "ICN"}, {"A", "C"}};
        HashMap<String, Integer> locationMap = new HashMap<>();
        int mapCnt = 1;
        locationMap.put("ICN", 1);
        map.put(1, "ICN");
        for(int i=0; i<10005; i++) {
            arrayList[i] = new ArrayList<Node>();
        }

        for(int i=0; i<tickets.length; i++) {
            String t1 = tickets[i][0];
            String t2 = tickets[i][1];
            int nt1, nt2;
            if(!locationMap.containsKey(t1)) {
                locationMap.put(t1, ++mapCnt);
                map.put(mapCnt, t1);
            }
            if(!locationMap.containsKey(t2)) {
                locationMap.put(t2, ++mapCnt);
                map.put(mapCnt, t2);
            }

            nt1 = locationMap.get(t1);
            nt2 = locationMap.get(t2);
            check[nt1][nt2] += 1;
            arrayList[nt1].add(new Node(nt2, t2));
        }
        answerCnt = tickets.length;
        answer = new String[answerCnt+1];

        for(int i=1; i<=mapCnt; i++) {
            Collections.sort(arrayList[i], new Comparator<Node>() {
                @Override
                public int compare(Node o1, Node o2) {
                    return o1.location.compareTo(o2.location);
                }
            });
        }

        dfs(1, "ICN", 0, tickets.length);
        answer[answerCnt] = "ICN";
        for(int i=0; i<=tickets.length; i++) {
            System.out.println(answer[i]);
        }
    }
}
