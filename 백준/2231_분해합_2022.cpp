#include <iostream>
#include <algorithm>
using namespace std;
int checkNumber(int N) {
    int number = N;
    while(N>0) {
        number += (N%10);
        N /= 10;
    }
    
    return number;
}
int main(void) {
    int N, answer=0;
    scanf("%d", &N);
    for(int i=1; i<N; i++) {
        int number = checkNumber(i);
        if(number == N) {
            answer = i;
            break;
        }
    }
    
    printf("%d\n", answer);
    return 0;
}
