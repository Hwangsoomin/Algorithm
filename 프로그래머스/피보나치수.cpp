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
int n=3;

int answer;
int fibo[100005];
int main(void) {
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2; i<=n; i++) {
        int sum = fibo[i-1] + fibo[i-2];
        fibo[i] = sum % 1234567;
    }
    answer = fibo[n];
    
    cout << answer << endl;
    return 0;
}
