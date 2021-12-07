#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
#define ll long long
using namespace std;
vector<string> grid={"S"};

int n,m, ans;
char arr[505][505];
int check[505][505][5];
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
queue<pair<pair<int, int>, pair<int, int>>> q;
vector<int> answer;
void bfs() {
    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dir = q.front().second.first;
        int len = q.front().second.second;
        ans = len;
        check[r][c][dir] = 1;
        q.pop();
        if(arr[r][c]=='L') dir = dir==0 ? 3 : dir-1;
        else if(arr[r][c]=='R') dir = dir==3 ? 0 : dir+1;
        
        int nr = (r + dr[dir] + n) % n;
        int nc = (c + dc[dir] + m) % m;
        if(!check[nr][nc][dir]) {
            check[nr][nc][dir] = 1;
            q.push({{nr, nc}, {dir, len+1}});
        }
    }
    answer.push_back(ans);
}
int main(void) {
    n = grid.size();
    m = grid[0].length();
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[i].length(); j++) {
            arr[i][j] = grid[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<4; k++) {
                if(!check[i][j][k]) {
                    ans = 0;
                    q.push({{i,j},{k,1}});
                    bfs();
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] <<endl;
    return 0;
}
