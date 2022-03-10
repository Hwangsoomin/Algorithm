#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m, a, b, cnt, answer;
int check[505];
vector<int> u[505], d[505];
void dfs(vector<int> t[], int here) {
    check[here] = 1;
    for(int i=0; i<t[here].size(); i++) {
        int next = t[here][i];
        if(!check[next]) {
            check[next] = 1;
            cnt += 1;
            dfs(t, next);
        }
    }
}
int main(void) {
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d%d", &a, &b);
        u[a].push_back(b);
        d[b].push_back(a);
    }
    for(int i=1; i<=n; i++) {
        cnt = 0;
        memset(check, 0, sizeof(check));
        dfs(u, i);
        memset(check, 0, sizeof(check));
        dfs(d, i);
        
        if(cnt == n-1) answer += 1;
    }
    
    printf("%d\n", answer);
    return 0;
}
