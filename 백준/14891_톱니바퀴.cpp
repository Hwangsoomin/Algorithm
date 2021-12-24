#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <deque>
#define ll long long
using namespace std;
int a, k, num, d, nd, answer;
deque<int> dq[5];
pair<int, int> point[5] = {{0,0}, {0,1}, {0,2}, {0,4}, {0,8}};
void rotate(int n, int wheelNum) { // 방향, 톱니바퀴 번호
    if(n==1) {
        int last = dq[wheelNum].back();
        dq[wheelNum].pop_back();
        dq[wheelNum].push_front(last);
        nd = -1;
    }
    else {
        int first = dq[wheelNum].front();
        dq[wheelNum].pop_front();
        dq[wheelNum].push_back(first);
        nd = 1;
    }
}
int main(void) {
    for(int i=1; i<=4; i++) {
        for(int j=1; j<=8; j++) {
            scanf("%1d", &a);
            dq[i].push_back(a);
        }
    }
    scanf("%d", &k);
    for(int i=1; i<=k; i++) {
        scanf("%d%d", &num, &d);
        if(d==1) nd = -1;
        else nd = 1;
        int pre1 = dq[num][6];
        int pre2 = dq[num][2];
        for(int j=num-1; j>=1; j--) {
            int nPre = dq[j][6];
            if(dq[j][2] != pre1) rotate(nd, j);
            else break;
            pre1 = nPre;
        }
        if(d==1) nd = -1;
        else nd = 1;
        for(int j=num+1; j<=4; j++) {
            int nPre = dq[j][2];
            if(dq[j][6] != pre2) rotate(nd, j);
            else break;
            pre2 = nPre;
        }
        rotate(d, num);
    }
    for(int i=1; i<=4; i++) {
        if(dq[i][0]==0) answer += point[i].first;
        else answer += point[i].second;
    }
    
    printf("%d\n", answer);
    return 0;
}
