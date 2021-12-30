#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <deque>
using namespace std;
int n, k, answer;
int check[300005];
queue<int> q;
void bfs() {
    q.push(n);
    check[n] = 1;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        if(here==k) {
            answer += 1;
            continue;
        }
        int next = here - 1;
        if(next>=0) {
            if(!check[next] || check[next]==check[here]+1){
                check[next] = check[here] + 1;
                q.push(next);
            }
        }
        next = here + 1;
        if(next<300005) {
            if(!check[next] || check[next]==check[here]+1){
                check[next] = check[here] + 1;
                q.push(next);
            }
        }
        next = here * 2;
        if(next<300005) {
            if(!check[next] || check[next]==check[here]+1){
                check[next] = check[here] + 1;
                q.push(next);
            }
        }
    }
}
int main(void) {
    scanf("%d%d", &n, &k);
    bfs();
    printf("%d\n%d\n", check[k]-1, answer);
    return 0;
}
