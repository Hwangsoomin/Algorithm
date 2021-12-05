#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
#define ll long long
using namespace std;
vector<vector<int>> maps={{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,1}};

int arr[105][105], check[105][105], n, m, answer;
queue<pair<int, int>> q;
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
void bfs() {
    q.push({1,1});
    check[1][1] = 1;
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<1 || nr>n || nc<1 || nc>m) continue;
            if(!check[nr][nc] && arr[nr][nc]) {
                check[nr][nc] = check[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
}
int main(void) {
    n = maps.size();
    m = maps[0].size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            arr[i+1][j+1] = maps[i][j];
        }
    }
    bfs();
    
    if(!check[n][m]) answer = -1;
    else answer = check[n][m];
    
    cout << answer <<endl;
    return 0;
}
