#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <deque>
#define ll long long
using namespace std;
int k, V, E, u, v;
vector<int> arr[20005];
queue<int> q;
int check[20005];
bool flag = false;
void bfs(int num) {
    q.push(num);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        if(flag) continue;
        for(int i=0; i<arr[here].size(); i++) {
            int next = arr[here][i];
            if(check[next]==0) {
                if(check[here]==1) check[next] = -1;
                else if(check[here]==-1) check[next] = 1;
                q.push(next);
            }
            else {
                if(check[here]==check[next]) {
                    flag = true;
                    break;
                }
            }
        }
    }
}
int main(void) {
    scanf("%d", &k);
    while(k--) {
        flag = false;
        for(int i=1; i<=V; i++) arr[i].clear();
        memset(check, 0, sizeof(check));
        scanf("%d%d", &V, &E);
        for(int i=1; i<=E; i++) {
            scanf("%d%d", &u, &v);
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        for(int i=1; i<=V; i++) {
            if(check[i]==0) {
                check[i] = 1;
                bfs(i);
            }
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
