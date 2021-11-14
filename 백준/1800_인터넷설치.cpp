#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n, p, k, answer=-1;
int dist[1005];
vector<pair<int, int>> arr[1005];
int dijkstra(int num) {
    for(int i=1; i<=n; i++) dist[i] = 1e9;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()) {
        int here = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<arr[here].size(); i++) {
            int next = arr[here][i].first;
            int ncost = cost + (arr[here][i].second>num);
            if(dist[next]>ncost) {
                dist[next] = ncost;
                pq.push({dist[next], next});
            }
        }
        
    }
    return dist[n];
}
int main(void) {
    int a, b, c, l=0, r=0;
    scanf("%d%d%d", &n, &p, &k);
    for(int i=1; i<=n; i++) dist[i] = 1e9;
    for(int i=1; i<=p; i++) {
        scanf("%d%d%d", &a, &b, &c);
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
        r = max(r, c);
    }
    while(l<=r) {
        int mid = (l+r)/2;
        int cnt = dijkstra(mid);
        if(cnt<=k) {
            answer = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    printf("%d\n", answer);
    return 0;
}
