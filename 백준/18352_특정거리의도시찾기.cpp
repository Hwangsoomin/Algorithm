#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, k, x, a, b;
vector<int> arr[300005];
int dist[300005];
vector<int> answer;
void di(int h) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, h});
    dist[h] = 0;
    while(!pq.empty()) {
        int here = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<arr[here].size(); i++) {
            int next = arr[here][i];
            int ncost = cost + 1;
            if(dist[next] > ncost) {
                dist[next] = ncost;
                pq.push({dist[next], next});
            }
        }
    }
}
int main(void) {
    scanf("%d%d%d%d", &n, &m, &k, &x);
    for(int i=1; i<=n; i++) {
        dist[i] = 1e9;
    }
    for(int i=1; i<=m; i++) {
        scanf("%d%d", &a, &b);
        arr[a].push_back(b);
    }
    di(x);
    
    for(int i=1; i<=n; i++) {
        if(dist[i] == k) {
            answer.push_back(i);
        }
    }
    if(!answer.size()) {
        answer.push_back(-1);
    }
    sort(answer.begin(), answer.end());
    for(int i=0; i<answer.size(); i++) {
        printf("%d\n", answer[i]);
    }
    return 0;
}
