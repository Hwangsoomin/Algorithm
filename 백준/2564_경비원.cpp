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
int x, y, n, d, dist, a, b, answer;
vector<pair<int, int>> arr;
int main(void) {
    scanf("%d%d", &x, &y);
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d%d", &a, &b);
        arr.push_back({a, b});
    }
    scanf("%d%d", &d, &dist);
    
    for(int i=0; i<arr.size(); i++) {
        int nd = arr[i].first;
        int ndist = arr[i].second;
        int sum1 = 0;
        int sum2 = 0;
        if(d==1) {
            if(nd==1) sum1 = abs(dist-ndist);
            else if(nd==2) sum1 = dist+ndist+y;
            else if(nd==3) sum1 = dist+ndist;
            else (x-dist)+ndist;
        }
        else if(d==2) {
            if(nd==2) sum1 = abs(dist-ndist);
            else if(nd==3) sum1 = dist+(y-ndist);
            else if(nd==4) sum1 = (x-dist) + (y-ndist);
            else sum1 = dist+ndist+y;
        }
        else if(d==3) {
            if(nd==3) sum1 = abs(dist-ndist);
            else if(nd==4) sum1 = dist+ndist+x;
            else if(nd==1) sum1 = dist+ndist;
            else sum1 = (y-dist)+ndist;
        }
        else {
            if(nd==4) sum1 = abs(dist-ndist);
            else if(nd==1) sum1 = dist+(x-ndist);
            else if(nd==2) sum1 = (y-dist)+(x-ndist);
            else sum1 = dist+ndist+x;
        }
        sum2 = (2*x) + (2*y) - sum1;
        answer += min(sum1, sum2);
    }
    
    printf("%d\n", answer);
    return 0;
}
