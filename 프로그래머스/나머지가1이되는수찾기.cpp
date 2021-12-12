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
int n=10;

int answer;
int main(void) {
    n -= 1;
    for(int i=2; i<=n; i++) {
        if(n%i==0) {
            answer = i;
            break;
        }
    }
    
    cout << answer << endl;
    return 0;
}
