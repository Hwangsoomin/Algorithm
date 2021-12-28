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
int F, S, G, U, D, answer;
int check[1000005];
int dr[4]={-1, 0, 1, 0};
int dc[4]={0, 1, 0, -1};
queue<int> q;
vector<int> ele;
void bfs() {
    q.push(S);
    check[S] = 1;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i=0; i<ele.size(); i++) {
            int next = here + ele[i];
            if(next<1 || next>F) continue;
            if(!check[next]) {
                check[next] = check[here] + 1;
                q.push(next);
            }
        }
        
    }
}
int main(void) {
    scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);
    ele.push_back(U);
    ele.push_back(-D);
    bfs();
    answer = check[G] - 1;
    if(answer==-1) printf("use the stairs\n");
    else printf("%d\n", answer);
    return 0;
}
