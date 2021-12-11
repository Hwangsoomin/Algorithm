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
vector<vector<int>> costs={{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}};
int n=4;

vector<pair<int,int>> arr;
int answer, uf[105], cnt, num;
int find(int u) {
    if(uf[u]==u) return u;
    else return uf[u] = find(uf[u]);
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    uf[u] = v;
}
int main(void) {
    for(int i=0; i<costs.size(); i++) {
        int cost = costs[i][2];
        arr.push_back({cost, i});
    }
    for(int i=0; i<n; i++) uf[i] = i;
    sort(arr.begin(), arr.end());
    while(cnt<n-1) {
        int here = arr[num].second;
        int r = costs[here][0];
        int c = costs[here][1];
        int cost = costs[here][2];
        if(find(r)!=find(c)) {
            cnt += 1;
            answer += cost;
            merge(r, c);
        }
        num+=1;
    }
    
    cout << answer << endl;
    return 0;
}
