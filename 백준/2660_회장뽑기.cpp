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
int n, a, b, Max, Min = 1e9;
int fw[55][55], point[55];
vector<int> answer;
int main(void) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            fw[i][j] = 1e9;
        }
    }
    for(int i=1; i<=n; i++) {
        fw[i][i] = 0;
    }
    while(1) {
        scanf("%d%d", &a, &b);
        if(a==-1 && b==-1) break;
        fw[a][b] = 1;
        fw[b][a] = 1;
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(fw[i][j] > fw[i][k] + fw[k][j]) {
                    fw[i][j] = fw[i][k] + fw[k][j];
                }
            }
        }
    }
    for(int i=1; i<=n; i++) {
        Max = 0;
        for(int j=1; j<=n; j++) {
            if(i==j) continue;
            Max = max(Max, fw[i][j]);
        }
        point[i] = Max;
        Min = min(Min, point[i]);
    }
    for(int i=1; i<=n; i++) {
        if(Min==point[i]) {
            answer.push_back(i);
        }
    }
    printf("%d %d\n", Min, answer.size());
    for(int i=0; i<answer.size(); i++) {
        printf("%d ", answer[i]);
    }
    return 0;
}
