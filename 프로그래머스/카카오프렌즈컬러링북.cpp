#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
using namespace std;
int m=6, n=4;
vector<vector<int>> picture={{1,1,1,0}, {1,2,2,0}, {1,0,0,1}, {0,0,0,1}, {0,0,0,3}, {0,0,0,3}};

int arr[105][105], check[105][105];
int number_of_area, max_size_of_one_area;
int dr[4]={-1, 0, 1, 0};
int dc[4]={0, 1, 0, -1};
vector<int> answer(2);
queue<pair<int, int>> q;
void bfs(int num) {
    int cnt = 0;
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        cnt += 1;
        check[r][c] = 1;
        for(int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<1 || nr>m || nc<1 || nc>n) continue;
            if(!check[nr][nc] && arr[nr][nc]==num) {
                check[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
    max_size_of_one_area = max(max_size_of_one_area, cnt);
}
int main(void) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            arr[i+1][j+1] = picture[i][j];
        }
    }
    
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(!check[i][j] && arr[i][j]!=0) {
                number_of_area += 1;
                q.push({i, j});
                bfs(arr[i][j]);
            }
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    for(int i=0; i<2; i++) {
        printf("%d\n", answer[i]);
    }
    return 0;
}
