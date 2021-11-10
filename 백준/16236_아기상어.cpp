#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, answer, sharkWeight=2, fishCnt;
int arr[25][25], check[25][25], checkFish[25][25];
int dr[4]={-1, 0, 1, 0};
int dc[4]={0, 1, 0, -1};
queue<pair<int, int>> q;
vector<pair<int, pair<int, int>>> edibleFish;
void bfs() {
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr<1||nr>n||nc<1||nc>n||arr[nr][nc]>sharkWeight)continue;
            if(check[nr][nc]) continue;
            check[nr][nc] = check[r][c] + 1;
            if(0<arr[nr][nc] && arr[nr][nc]<sharkWeight && !checkFish[nr][nc]) edibleFish.push_back({{check[r][c]}, {nr, nc}});
            q.push({nr, nc});
        }
    }
}
int main(void) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==9){
                check[i][j] = 1;
                q.push({i, j});
                arr[i][j] = 0;
            }
        }
    }
    while(1) {
        bfs();
        if(edibleFish.size()==0) break;
        sort(edibleFish.begin(), edibleFish.end());
        int fishX = edibleFish[0].second.first;
        int fishY = edibleFish[0].second.second;
        int cnt = edibleFish[0].first;
        edibleFish.clear();
        for(int i=1; i<=n; i++)memset(check[i], 0, sizeof(check[i]));
        
        answer += cnt;
        fishCnt += 1;
        if(fishCnt == sharkWeight) { //상어의 크기와 먹은 물고기 수가 같을 때  상어의 크기는 1증가
            sharkWeight += 1;
            fishCnt = 0;
        }
        checkFish[fishX][fishY] = 1;
        check[fishX][fishY] = 1;
        q.push({fishX, fishY});
    }
    
    printf("%d\n", answer);
    return 0;
}
