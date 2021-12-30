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
int t, n, x, y;
int dist[105][105];
pair<int, int> store[105];
int main(void) {
    scanf("%d", &t);
    while(t--) {
        for(int i=0; i<=n; i++) store[i] = {0, 0};
        scanf("%d", &n);
        for(int i=1; i<=n+2; i++) {
            for(int j=1; j<=n+2; j++) {
                dist[i][j] = 1e9;
            }
        }
        for(int i=1; i<=n+2; i++) {
            scanf("%d%d", &x, &y);
            store[i] = {x, y};
            dist[i][i] = 0;
        }
        for(int i=1; i<=n+2; i++) {
            for(int j=i+1; j<=n+2; j++) {
                int d = abs(store[i].first-store[j].first) + abs(store[i].second-store[j].second);
                if(d<=1000) dist[i][j] = dist[j][i] = 1;
            }
        }
        for(int k=1; k<=n+2; k++) {
            for(int i=1; i<=n+2; i++) {
                for(int j=1; j<=n+2; j++) {
                    if(dist[i][j]>dist[i][k]+dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        if(dist[1][n+2]!=1e9) printf("happy\n");
        else printf("sad\n");
    }
    return 0;
}
