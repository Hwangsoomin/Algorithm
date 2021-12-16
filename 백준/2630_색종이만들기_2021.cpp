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
int n;
int arr[130][130];
vector<int> ans(2, 0);
void go(int r, int c, int cnt) {
    bool Zero = true, One = true;
    for(int i=r; i<r+cnt; i++) {
        for(int j=c; j<c+cnt; j++) {
            if(arr[i][j]==0) One = false;
            else if(arr[i][j]==1) Zero = false;
        }
    }
    if(Zero) {
        ans[0] += 1;
        return;
    }
    if(One) {
        ans[1] += 1;
        return;
    }
    go(r, c, cnt/2);
    go(r, c+cnt/2, cnt/2);
    go(r+cnt/2, c, cnt/2);
    go(r+cnt/2, c+cnt/2, cnt/2);
}
int main(void) {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf(" %d", &arr[i][j]);
        }
     }
    go(0, 0, n);
    for(int i=0; i<ans.size(); i++) printf("%d\n", ans[i]);
    return 0;
}
