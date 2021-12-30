#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <deque>
using namespace std;
int n, k, answer;
int check[200005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void bfs() {
    pq.push({0, n});
    while(!pq.empty()) {
        int cnt = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(here==k) {
            answer = cnt;
            break;
        }
        int next = here * 2;
        if(next<200005 && next!=0 && !check[next]) {
            check[next] = 1;
            pq.push({cnt, next});
        }
        next = here + 1;
        if(next<200005 && !check[next]) {
            check[next] = 1;
            pq.push({cnt+1, next});
        }
        next = here - 1;
        if(next>=0 && !check[next]) {
            check[next] = 1;
            pq.push({cnt+1, next});
        }
    }
}
int main(void) {
    scanf("%d%d", &n, &k);
    bfs();
    printf("%d\n", answer);
    return 0;
}
