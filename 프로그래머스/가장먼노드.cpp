#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
#define ll long long
using namespace std;
int n=6;
vector<vector<int>> edge={{3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2}};

vector<int> arr[20005];
int dist[20005];
int Max, answer;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void di() {
    pq.push({0, 1});
    dist[1]=0;
    while(!pq.empty()) {
        int here = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        Max = max(Max, cost);
        if(dist[here]<cost) continue;
        for(int i=0; i<arr[here].size(); i++) {
            int next = arr[here][i];
            if(dist[next]>cost+1) {
                dist[next] = cost+1;
                pq.push({dist[next], next});
            }
        }
    }
}
int main(void) {
    for(int i=0; i<edge.size(); i++) {
        int n1=edge[i][0];
        int n2=edge[i][1];
        arr[n1].push_back(n2);
        arr[n2].push_back(n1);
    }
    for(int i=1; i<=n; i++) dist[i]=1e9;
    di();
    for(int i=1; i<=n; i++) {
        if(dist[i]==Max) answer+=1;
    }
    printf("%d\n", answer);
    return 0;
}
