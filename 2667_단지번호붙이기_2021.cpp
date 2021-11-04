#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n, cnt;
int arr[30][30],check[30][30];
int dr[4]={-1, 0,1,0};
int dc[4]={0,1,0,-1};
queue<pair<int,int>> q;
vector<int> answer;
void bfs(int x, int y) {
    q.push({x, y});
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        cnt += 1;
        check[r][c] = 1;
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<0 || nr>n || nc<1 || nc>n) continue;
            if(!check[nr][nc] && arr[nr][nc]) {
                check[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
}
int main(void) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    for(int i=1; i<=n ;i++){
        for(int j=1; j<=n; j++){
            if(!check[i][j] && arr[i][j]){
                cnt = 0;
                bfs(i,j);
                answer.push_back(cnt);
            }
        }
    }
    sort(answer.begin(), answer.end());
    printf("%d\n", answer.size());
    for(int i=0; i<answer.size(); i++){
        printf("%d\n",answer[i]);
    }
    return 0;
}