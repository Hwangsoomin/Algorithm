#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int t, m, n, k, a, b, answer;
int arr[55][55], check[55][55];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
queue<pair<int,int>> q;
void bfs(int x, int y) {
    q.push({x, y});
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        check[r][c] = 1;
        for(int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
            if(!check[nr][nc] && arr[nr][nc]) {
                check[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
}
int main(void) {
    scanf("%d", &t);
    while(t--) {
        answer = 0;
        for(int i=0; i<m; i++) {
           memset(arr[i], 0, sizeof(arr[i]));
           memset(check[i], 0, sizeof(check[i]));
        }
        scanf("%d%d%d", &m, &n, &k);
        for(int i=1; i<=k; i++){
            scanf("%d%d", &a, &b);
            arr[a][b] = 1;
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!check[i][j] && arr[i][j]) {
                    answer += 1;
                    bfs(i, j);
                }
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}