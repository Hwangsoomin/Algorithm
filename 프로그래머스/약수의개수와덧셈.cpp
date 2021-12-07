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
int Left=13, Right=17;

int answer;
void go(int num) {
    int cnt=0;
    for(int i=1; i<=num; i++) {
        int nnum = num/i;
        if(nnum<i) break;
        if(num%i==0) {
            if(i==nnum) cnt += 1;
            else cnt += 2;
        }
    }
    if(cnt%2==0) answer += num;
    else answer -= num;
}
int main(void) {
    for(int i=Left; i<=Right; i++) {
        go(i);
    }
    
    cout << answer <<endl;
    return 0;
}
