#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#define ll long long
using namespace std;
int n, a, b, Max, answer, MaxEm;
vector<int> arr, student[405];
vector<pair<int, int>> sitting;
int check[25][25], sit[25][25], checkPeo[25][25], checkEm[25][25];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int sum[5] = {0, 1, 10, 100, 1000};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
queue<pair<int, int>> q;
int main(void) {
    scanf("%d", &n);
    for(int i=1; i<=n*n; i++) {
        scanf("%d", &a);
        arr.push_back(a);
        for(int j=1; j<=4; j++) {
            scanf("%d", &b);
            student[a].push_back(b);
        }
    }
    for(int i=0; i<arr.size(); i++) {
        int hereS = arr[i];
        Max = 0;
        MaxEm = 0;
        for(int j=0; j<=n; j++) {
            memset(checkPeo[j], 0, sizeof(checkPeo[j]));
            memset(checkEm[j], 0, sizeof(checkEm[j]));
        }
        sitting.clear();
        for(int r=1; r<=n; r++) {
            for(int c=1; c<=n; c++) {
                if(!check[r][c]) {
                    for(int k=0; k<4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if(nr<1 || nr>n || nc<1 || nc>n) continue;
                        for(int j=0; j<student[hereS].size(); j++) {
                            int st = student[hereS][j];
                            if(st==sit[nr][nc]) {
                                checkPeo[r][c] += 1;
                                Max = max(Max, checkPeo[r][c]);
                            }
                        }
                    }
                    sitting.push_back({r, c});
                }
            }
        }
        while(!pq.empty()) pq.pop();
        while(!q.empty()) q.pop();
        for(int j=0; j<sitting.size(); j++) {
            int r = sitting[j].first;
            int c = sitting[j].second;
            if(checkPeo[r][c] == Max) {
                int emptyCnt = 0;
                q.push({r, c});
                for(int k=0; k<4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if(nr<1 || nr>n || nc<1 || nc>n) continue;
                    if(!sit[nr][nc]) emptyCnt += 1;
                }
                checkEm[r][c] = emptyCnt;
                MaxEm = max(MaxEm, emptyCnt);
            }
        }
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(checkEm[r][c] == MaxEm) pq.push({r, c});
        }
        sit[pq.top().first][pq.top().second] = hereS;
        check[pq.top().first][pq.top().second] = 1;
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int hereS = sit[i][j];
            int cnt = 0;
            for(int k=0; k<student[hereS].size(); k++) {
                int fr = student[hereS][k]; // 좋아하는 친구
                for(int z=0; z<4; z++) { // 인접하는 자리
                    int nr = i + dr[z]; //인접하는 자리 행
                    int nc = j + dc[z]; //인접하는 자리 열
                    if(nr<1 || nr>n || nc<1 || nc>n) continue;
                    if(sit[nr][nc]==fr) cnt += 1;
                }
            }
            answer += sum[cnt];
        }
    }
    
    printf("%d\n", answer);
    return 0;
}
