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
int n=8, a=4, b=7;

int answer;
int main(void) {
    while(a!=b) {
        answer += 1;
        if(a%2==0) a/= 2;
        else a = (a+1)/2;
        
        if(b%2==0) b /= 2;
        else b = (b+1)/2;
    }
    
    cout << answer <<endl;
    return 0;
}
