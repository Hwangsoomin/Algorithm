#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int N, Q, p, q, r, k, v;
vector<pair<int, int>> arr[5005];
int check[5005];
int answer;
void go(int here, int cost) {
    if(cost>=k && cost!=1e9) answer += 1;
    check[here] = 1;
    for(int i=0; i<arr[here].size(); i++){
        int next = arr[here][i].first;
        int ncost = arr[here][i].second;
        if(!check[next]) {
            check[next] = 1;
            go(next, min(cost, ncost));
        }
    }
}
int main(void) {
    scanf("%d%d", &N, &Q);
    for(int i=1; i<N; i++) {
        scanf("%d%d%d", &p, &q, &r);
        arr[p].push_back({q, r});
        arr[q].push_back({p, r});
    }
    for(int i=1; i<=Q; i++) {
        answer = 0;
        memset(check, 0, sizeof(check));
        scanf("%d%d", &k, &v);
        go(v, 1e9);
        printf("%d\n", answer);
    }
    return 0;
}
