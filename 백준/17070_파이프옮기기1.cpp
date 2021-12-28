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
int n, answer;
int dr[4]={0, 1, 1};
int dc[4]={1, 0, 1};
int arr[20][20];
queue<pair<pair<int, int>, int>> q;
void bfs() {
    q.push({{1, 2}, 0});
    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        int cnt = 0;
        q.pop();
        if(r==n && c==n) {
            answer += 1;
            continue;
        }
        for(int i=0; i<3; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<1 || nr>n || nc<1 || nc>n) continue;
            if(!arr[nr][nc]) {
                if(d==0 && i==1) cnt += 1;
                else if(d==1 && i==0) cnt += 1;
                else {
                    if(cnt!=2 && i==2) continue;
                    q.push({{nr, nc}, i});
                    cnt += 1;
                }
            }
        }
    }
}
int main(void) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    bfs();
    printf("%d\n", answer);
    return 0;
}
