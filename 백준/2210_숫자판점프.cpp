#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
int arr[6][6];
map<string, int> m;
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
int answer;
void dfs(string str, int r, int c) {
    if(str.length()==6) {
        if(m.find(str)==m.end()) m[str] = ++answer;
        return;
    }
    for(int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr<1 || nr>5 || nc<1 || nc>5) continue;
        dfs(str+to_string(arr[nr][nc]), nr, nc);
    }
}
int main(void) {
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=5; j++) {
            string str = to_string(arr[i][j]);
            dfs(str, i, j);
        }
    }
    
    printf("%d\n", answer);
    return 0;
}
