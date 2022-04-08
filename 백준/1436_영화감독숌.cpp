#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    int n, answer = 0, number = 0;
    scanf("%d", &n);
    
    while(number != n) {
        answer += 1;
        int temp = answer;
        while(temp>=666) {
            if(temp % 1000 == 666) {
                number += 1;
                break;
            }
            else temp /= 10;
        }
    }
    
    printf("%d\n", answer);
    return 0;
}
