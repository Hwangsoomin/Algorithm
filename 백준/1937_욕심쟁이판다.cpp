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
int dp[505][505], arr[505][505];
int dr[4]={-1, 0, 1, 0};
int dc[4]={0, 1, 0, -1};
int dfs(int r, int c) {
    if(dp[r][c]==-1) dp[r][c] = 0;
    else return dp[r][c];
    for(int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr<1 || nr>n || nc<1 || nc>n) continue;
        if(arr[r][c] >= arr[nr][nc]) continue;
        dp[r][c] = max(dp[r][c], dfs(nr, nc));
    }
    return dp[r][c] = dp[r][c] + 1;
}
int main(void) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &arr[i][j]);
            dp[i][j] = -1;
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(dp[i][j] == -1) {
                dfs(i, j);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            answer = max(answer, dp[i][j]);
        }
    }
    
    printf("%d\n", answer);
    return 0;
}
