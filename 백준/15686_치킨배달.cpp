#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int n, m, a, answer=1e9;
int check[15];
vector<pair<int, int>> home, chicken, checkedC;
int distance() {
    int sum = 0;
    for(int i=0; i<home.size(); i++) {
        int dist = 0;
        int Min = 1e9;
        for(int j=0; j<checkedC.size(); j++) {
            dist = abs(home[i].first-checkedC[j].first) + abs(home[i].second-checkedC[j].second);
            Min = min(Min, dist);
        }
        sum += Min;
    }
    return sum;
}

void pickChicken(int here, int cnt) {
    if(cnt==m) {
        int dist = distance();
        answer = min(answer, dist);
        return;
    }
    
    for(int i=here; i<chicken.size(); i++) {
        if(check[i]) continue;
        check[i] = 1;
        checkedC.push_back({chicken[i].first, chicken[i].second});
        pickChicken(i+1, cnt+1);
        checkedC.pop_back();
        check[i] = 0;
    }
}
int main(void) {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &a);
            if(a==1) home.push_back({i, j});
            if(a==2) chicken.push_back({i, j});
        }
    }
    
    pickChicken(0, 0);
    printf("%d\n", answer);
    return 0;
}
