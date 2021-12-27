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
int n, L, R, cnt, sum, answer;
int arr[55][55], check[55][55], narr[55][55];
int dr[4]={-1, 0, 1, 0};
int dc[4]={0, 1, 0, -1};
vector<pair<int, int>> point;
void dfs(int r, int c) {
    check[r][c] = 1;
    point.push_back({r, c});
    for(int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr<1 || nr>n || nc<1 || nc>n) continue;
        if(abs(arr[r][c]-arr[nr][nc])<L || abs(arr[r][c]-arr[nr][nc])>R) continue;
        if(!check[nr][nc]) {
            check[nr][nc] = 1;
            cnt += 1;
            sum += arr[nr][nc];
            dfs(nr, nc);
        }
    }
}
int main(void) {
    scanf("%d%d%d", &n, &L, &R);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    while(1) {
        bool flag = false;
        for(int i=1; i<=n; i++) memset(check[i], 0, sizeof(check[i]));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cnt = 1;
                sum = arr[i][j];
                point.clear();
                if(!check[i][j]){
                    dfs(i, j);
                    int num = sum / cnt;
                    if(point.size()!=1) flag = true;
                    for(int x=0; x<point.size(); x++) {
                        int r = point[x].first;
                        int c = point[x].second;
                        narr[r][c] = num;
                    }
                }
            }
        }
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(!narr[i][j]) narr[i][j] = arr[i][j];
                arr[i][j] = narr[i][j];
            }
        }
        if(!flag) break;
        answer += 1;
    }
    
    printf("%d\n", answer);
    return 0;
}
