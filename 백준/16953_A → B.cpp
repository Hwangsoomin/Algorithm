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
priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;
long long a, b;
int answer;
int main(void) {
    scanf("%lld%lld", &a, &b);
    pq.push({0, a});
    while(!pq.empty()) {
        int cnt = pq.top().first;
        long long num = pq.top().second;
        pq.pop();
        if(num==b) {
            answer = cnt + 1;
            break;
        }
        long long nnum = num * 2;
        if(nnum<=b) pq.push({cnt+1, nnum});
        nnum = num * 10 + 1;
        if(nnum<=b) pq.push({cnt+1, nnum});
    }
    if(!answer) answer = -1;
    printf("%d\n", answer);
    return 0;
}
