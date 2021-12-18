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
int n=15;

int answer;
int main(void) {
    for(int i=1; i<=n; i++) {
        int sum = 0;
        for(int j=i; j<=n; j++) {
            sum += j;
            if(sum>n) break;
            if(sum==n) {
                answer += 1;
                break;
            }
        }
    }
    
    cout << answer << endl;
    return 0;
}
