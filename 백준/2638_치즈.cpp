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
int n, m, minX=105, minY=105, maxX, maxY, answer;
int cheese[105][105], check[105][105];
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        check[r][c] = 1;
        q.pop();
        for(int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<1 || nr>n || nc<1 || nc>m) continue;
            if(!check[nr][nc] && !cheese[nr][nc]) {
                check[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
}
void checkAir() {
    for(int i=minX; i<=maxX; i++) {
        if(!cheese[minY][i]) {
            bfs(minY, i);
        }
        if(!cheese[maxY][i]) {
            bfs(maxY, i);
        }
    }
    for(int i=minY; i<=maxY; i++) {
        if(!cheese[i][minX]) {
            bfs(i, minX);
        }
        if(!cheese[i][maxX]) {
            bfs(i, maxX);
        }
    }
}
int main(void) {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d", &cheese[i][j]);
        }
    }
    while(1) {
        minX = 1e9; minY = 1e9; maxX = 0; maxY = 0;
        for(int i=1; i<=n; i++) memset(check[i], 0, sizeof(check[i]));
        vector<pair<int, int>> ec;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(cheese[i][j]==1) {
                    minX = min(minX, j);
                    maxX = max(maxX, j);
                    minY = min(minY, i);
                    maxY = max(maxY, i);
                }
            }
        }
        if(minX==1e9 && minY==1e9 && maxX==0 && maxY==0) break;
        checkAir(); // 치즈 안에 있는 공기는 아님을 체크하기 위함
        for(int i=minY+1; i<maxY; i++) {
            for(int j=minX+1; j<maxX; j++) {
                if(!cheese[i][j] && !check[i][j]) check[i][j] = 2;
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(cheese[i][j]) {
                    int cnt = 0;
                    for(int k=0; k<4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(nr<1 || nr>n || nc<1 || nc>m) continue;
                        if(!cheese[nr][nc] && check[nr][nc]!=2) cnt += 1;
                    }
                    if(cnt>=2) ec.push_back({i, j});
                }
            }
        }
        for(int i=0; i<ec.size(); i++) {
            int r = ec[i].first;
            int c = ec[i].second;
            cheese[r][c] = 0;
        }
        answer += 1;
    }
    printf("%d\n", answer);
    return 0;
}
