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
int a=3, b=5;
int main(void) {
    long long answer = 0;
    if(a>b) swap(a, b);
    for(int i=a; i<=b; i++) answer += i;
    
    cout << answer << endl;
    return 0;
}
