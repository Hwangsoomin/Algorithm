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
int n, m, answer;
char arr[55][55];
int check[55][55];
int dr[4]={-1, 0, 1, 0};
int dc[4]={0, 1, 0, -1};
queue<pair<int, int>> q;
void bfs(int x, int y) {
    for(int i=1; i<=n; i++) memset(check[i], 0, sizeof(check[i]));
    q.push({x, y});
    check[x][y] = 1;
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        answer = max(answer, check[r][c]-1);
        q.pop();
        for(int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<1 || nr>n || nc<1 || nc>m) continue;
            if(!check[nr][nc] && arr[nr][nc]=='L') {
                check[nr][nc] = check[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
}
int main(void) {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(arr[i][j]=='L') {
                bfs(i, j);
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}
