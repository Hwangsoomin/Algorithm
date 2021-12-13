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
int n=5000;

int ans;
int main(void) {
    while(n>0) {
        if(n%2!=0) ans += 1;
        n /= 2;
    }
    
    cout << ans << endl;
    return 0;
}
