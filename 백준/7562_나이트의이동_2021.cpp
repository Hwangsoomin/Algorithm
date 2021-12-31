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
int t, l, hx, hy, ax, ay;
int check[305][305];
int dr[8]={-2,-1,1,2,2,1,-1,-2};
int dc[8]={1,2,2,1,-1,-2,-2,-1};
queue<pair<int, int>> q;
void bfs() {
    q.push({hx, hy});
    check[hx][hy] = 1;
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0; i<8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<0 || nr >=l || nc<0 || nc>=l) continue;
            if(!check[nr][nc]) {
                check[nr][nc] = check[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
}
int main(void) {
    scanf("%d", &t);
    while(t--) {
        for(int i=0; i<=l; i++) memset(check[i], 0, sizeof(check[i]));
        scanf("%d", &l);
        scanf("%d%d", &hx, &hy);
        scanf("%d%d", &ax, &ay);
        bfs();
        printf("%d\n", check[ax][ay]-1);
    }
    return 0;
}
