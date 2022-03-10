#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m, k, v, w, Min = 1e9, answer;
int A[10005], check[10005];
vector<int> fr[10005];
void dfs(int here) {
    Min = min(Min, A[here]);
    check[here] = 1;
    for(int i=0; i<fr[here].size(); i++) {
        int next = fr[here][i];
        if(!check[next]) {
            dfs(next);
        }
    }
}
int main(void) {
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; i++) {
        scanf("%d", &A[i]);
    }
    for(int i=1; i<=m; i++) {
        scanf("%d%d", &v, &w);
        fr[v].push_back(w);
        fr[w].push_back(v);
    }
    for(int i=1; i<=n; i++) {
        if(!check[i]) {
            Min = 1e9;
            dfs(i);
            answer += Min;
        }
    }
    if(answer<=k) {
        printf("%d\n", answer);
    }
    else printf("Oh no\n");
    return 0;
}
