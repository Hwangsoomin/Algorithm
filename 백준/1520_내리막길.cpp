#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <deque>
#define ll long long
using namespace std;
int n, m, answer;
int arr[505][505], dp[505][505];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int dfs(int r, int c) {
    if(r==n && c==m) {
        return 1;
    }
    else if(dp[r][c] == -1) {
        dp[r][c] = 0;
        for(int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<1 || nr>n || nc<1 || nc>m) continue;
            if(arr[r][c] > arr[nr][nc]) {
                dp[r][c] += dfs(nr, nc);
            }
        }
    }
    return dp[r][c];
}
int main(void) {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf(" %d", &arr[i][j]);
            dp[i][j] = -1;
        }
    }
    answer = dfs(1, 1);
    
    printf("%d\n", answer);
    return 0;
}
