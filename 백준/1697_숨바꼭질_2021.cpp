#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n, k, answer;
int check[100005];
queue<pair<int,int>> q;
void bfs() {
    q.push({n, 0});
    while(!q.empty()) {
        int here = q.front().first;
        int cnt = q.front().second;
        q.pop();
        check[here] = 1;
        if(here == k) answer = cnt;

        int next = here - 1;
        if(0<= here && here <=100000 && !check[next]) {
            check[next] = 1;
            q.push({next, cnt + 1});
        }
        next = here + 1;
        if(0<= next && next <=100000 && !check[next]) {
            check[next] = 1;
            q.push({next, cnt + 1});
        }
        next = here * 2;
        if(0<= next && next <=100000 && !check[next]) {
            check[next] = 1;
            q.push({next, cnt + 1});
        }
    }
}

int main(void) {
    scanf("%d%d", &n, &k);
    bfs();

    printf("%d\n", answer);
    return 0;
}