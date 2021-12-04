#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
#define ll long long
using namespace std;
int n=125;

ll num;
int answer, gob=1;
int main(void) {
    while(n>0) {
        num = (num*10)+(n%3);
        n/=3;
    }
    while(num>0) {
        answer += ((num%10)*gob);
        gob*=3;
        num/=10;
    }
    
    cout << answer << endl;
    return 0;
}
