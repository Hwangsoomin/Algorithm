#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int m, n, total_tomato, cnt_tomato, answer;
int arr[1005][1005], check[1005][1005];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
void bfs() {
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        cnt_tomato += 1;
        answer = max(answer, check[r][c]);
        for(int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<1 || nr>n|| nc<1 || nc>m) continue;
            if(!check[nr][nc] && arr[nr][nc]==0) {
                check[nr][nc] = check[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
}
int main(void) {
    scanf("%d%d", &m, &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 0 || arr[i][j] == 1) {
                total_tomato += 1;
                if(arr[i][j]) {
                    check[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
    }
    bfs();
    answer -= 1;
    if(total_tomato != cnt_tomato) printf("-1\n");
    else printf("%d\n", answer);
    return 0;
}