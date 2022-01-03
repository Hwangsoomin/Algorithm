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
int s, answer;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int check[2005][2005];
int main(void) {
    scanf("%d", &s);
    pq.push({0, {1, 0}});
    while(!pq.empty()) {
        int cnt = pq.top().first;
        int screenCnt = pq.top().second.first;
        int clipCnt = pq.top().second.second;
        pq.pop();
        check[screenCnt][clipCnt] = 1;
        if(screenCnt==s) {
            answer = cnt;
            break;
        }
        if(!check[screenCnt][screenCnt]) {
            check[screenCnt][screenCnt] = 1;
            pq.push({cnt+1, {screenCnt, screenCnt}});
        }
        if(clipCnt!=0 && screenCnt+clipCnt<2005) {
            if(!check[screenCnt+clipCnt][clipCnt]) {
                check[screenCnt+clipCnt][clipCnt] = 1;
                pq.push({cnt+1, {screenCnt+clipCnt, clipCnt}});
            }
        }
        if(screenCnt>=1) {
            if(!check[screenCnt-1][clipCnt]) {
                check[screenCnt-1][clipCnt] = 1;
                pq.push({cnt+1, {screenCnt-1, clipCnt}});
            }
        }
    }
    
    printf("%d\n", answer);
    return 0;
}
