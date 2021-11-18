#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int n, answer=1e9;
int main(void) {
    scanf("%d", &n);
    for(int i=0; i<=1000; i++) {
        for(int j=0; j<1700; j++) {
            if((5*i)+(3*j) == n) answer = min(answer, (i+j));
        }
    }
    if(answer==1e9) answer = -1;
    printf("%d\n", answer);
    return 0;
}
