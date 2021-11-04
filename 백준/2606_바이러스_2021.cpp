#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n, m, a, b, answer = -1;
int check[105];
vector<int> arr[105];
void dfs(int here) {
    check[here] = 1;
    answer += 1;
    for(int i=0 ;i<arr[here].size(); i++){
        int next = arr[here][i];
        if(!check[next]){
            check[next] = 1;
            dfs(next);
        }
    }
}
int main(void) {
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1; i<=m; i++){
        scanf("%d%d", &a, &b);
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1);
    printf("%d\n", answer);
    return 0;
}