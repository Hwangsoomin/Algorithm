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
vector<vector<int>> wires={{1,2},{2,7},{3,7},{3,4},{4,5},{6,7}};
int n=7;

int answer=1e10, cnt;
int check[105], wire[105][105];
vector<int> arr[105];
void dfs(int here) {
    check[here] = 1;
    cnt += 1;
    for(int i=0; i<arr[here].size(); i++) {
        int next = arr[here][i];
        if(!check[next] && !wire[here][next]) {
            check[next] = 1;
            dfs(next);
        }
    }
}
int main(void) {
    for(int i=0; i<wires.size(); i++) {
        int r = wires[i][0];
        int c = wires[i][1];
        arr[r].push_back(c);
        arr[c].push_back(r);
    }
    for(int i=0; i<wires.size(); i++) {
        int r = wires[i][0];
        int c = wires[i][1];
        wire[r][c] = 1;
        wire[c][r] = 1;
        memset(check, 0, sizeof(check));
        int cnt1=0, cnt2=0;
        for(int j=1; j<=n; j++) {
            cnt = 0;
            if(!check[j]) {
                dfs(j);
                if(!cnt1) cnt1 = cnt;
                else cnt2 = cnt;
            }
        }
        wire[r][c] = 0;
        wire[c][r] = 0;
        answer = min(answer, abs(cnt1-cnt2));
    }
    
    cout << answer << endl;
    return 0;
}
