#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#define ll long long
using namespace std;
vector<vector<int>> road={{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
int N=5, K=3;

vector<pair<int, int>> arr[55];
int dist[55], answer;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void di() {
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here]<cost) continue;
        for(int i=0; i<arr[here].size(); i++) {
            int next = arr[here][i].first;
            int nCost = arr[here][i].second + dist[here];
            if(dist[next]>nCost) {
                dist[next] = nCost;
                pq.push({nCost, next});
            }
        }
    }
}
int main(void) {
    for(int i=0; i<road.size(); i++) {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }
    for(int i=1; i<=N; i++) dist[i] = 1e9;
    di();
    for(int i=1; i<=N; i++) {
        if(dist[i]<=K) answer += 1;
    }
    
    cout << answer <<endl;
    return 0;
}
