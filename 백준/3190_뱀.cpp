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
int n, k, l, a, b, dir, sum, answer;
char c;
pair<int, int> snake[2];
int arr[105][105];
vector<pair<int, char>> dis;
bool flag = false;
void go(int cnt) {
    while(cnt--) {
        pair<int, int> head = snake[0];
        pair<int, int> tail = snake[1];
        arr[head.first][head.second] = dir;
        if(dir==1) head.second += 1;
        else if(dir==2) head.first += 1;
        else if(dir==3) head.second -= 1;
        else head.first -= 1;
        answer += 1;
        if(arr[head.first][head.second]>=1 && arr[head.first][head.second]<=4) {
            flag = true;
            break;
        }
        if(head.first<1 || head.first>n || head.second<1 || head.second>n) {
            flag = true;
            break;
        }
        if(arr[head.first][head.second]!=5) {
            if(arr[tail.first][tail.second]==1) tail.second += 1;
            else if(arr[tail.first][tail.second]==2) tail.first += 1;
            else if(arr[tail.first][tail.second]==3) tail.second -= 1;
            else tail.first -= 1;
            arr[snake[1].first][snake[1].second] = 0;
        }
        else arr[head.first][head.second] = dir;
        snake[0] = head;
        snake[1] = tail;
    }
}
int main(void) {
    scanf("%d%d", &n, &k);
    snake[0] = {1, 1};
    snake[1] = {1, 1};
    dir = 1;
    for(int i=1; i<=k; i++) {
        scanf("%d%d", &a, &b);
        arr[a][b] = 5;
    }
    scanf("%d", &l);
    for(int i=1; i<=l; i++) {
        scanf("%d", &a);
        scanf(" %c", &c);
        dis.push_back({a, c});
    }
    for(int i=0; i<l; i++) {
        int cnt = dis[i].first - sum;
        char ndir = dis[i].second;
        go(cnt);
        sum = dis[i].first;
        if(flag) break;
        if(ndir=='D') dir += 1;
        else dir -= 1;
        if(dir==0) dir = 4;
        else if(dir==5) dir = 1;
    }
    if(!flag) go(10000);
    printf("%d\n", answer);
    return 0;
}
