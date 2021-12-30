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
int n, k, num;
int check[300005], dist[300005];
queue<int> q;
deque<int> answer;
void bfs() {
    q.push(n);
    check[n] = 1;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        if(here==k) break;
        int next = here - 1;
        if(next>=0 && !check[next]) {
            check[next] = 1;
            dist[next] = here;
            q.push(next);
        }
        next = here + 1;
        if(next<300005 && !check[next]) {
            check[next] = 1;
            dist[next] = here;
            q.push(next);
        }
        next = here * 2;
        if(next<300005 && !check[next]) {
            check[next] = 1;
            dist[next] = here;
            q.push(next);
        }
    }
}
int main(void) {
    scanf("%d%d", &n, &k);
    bfs();
    int pre = k;
    while(pre!=n) {
        answer.push_front(pre);
        pre = dist[pre];
    }
    answer.push_front(pre);
    printf("%d\n", answer.size()-1);
    while(!answer.empty()) {
        printf("%d ", answer.front());
        answer.pop_front();
    }
    return 0;
}
