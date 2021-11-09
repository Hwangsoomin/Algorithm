#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, answer;
int check[55][55];
char arr[55][55];
char decoration[2] = {'-', '|'};
void dfs(int r, int c, int num) {
    check[r][c] = 1;
    int nr = r;
    int nc = c;
    if(num == 1) nc += 1;
    if(num == 2) nr += 1;

    if(nr<1 || nr>n || nc<1|| nc>m) return;
    if(arr[nr][nc]==decoration[num-1] && !check[nr][nc]){
        check[nr][nc] = 1;
        dfs(nr, nc, num);
    }
}
int main(void) {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf(" %c", &arr[i][j]);
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j]=='-' && !check[i][j]) {
                dfs(i, j, 1);
                answer += 1;
            }
            if(arr[i][j]=='|' && !check[i][j]) {
                dfs(i, j, 2);
                answer += 1;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}