#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int check[10], arr[10];
vector<int> answer;
int go(int here, int num, int sum) {
    if(sum == 100 && num == 7) {
        for(int i=1; i<=9; i++) {
            if(check[i]) {
                answer.push_back(arr[i]);
            }
        }
        return 1;
    }
    for(int i=here; i<=9; i++) {
        if(!check[i]) {
            check[i] = 1;
            if(go(i+1, num + 1, sum + arr[i])) return 1;
            check[i] = 0;
        }
    }
    return 0;
}
int main(void) {
    for(int i=1; i<=9; i++) {
        scanf("%d", &arr[i]);
    }
    go(1, 0, 0);
    
    for(int i=0; i<answer.size(); i++) {
        printf("%d\n", answer[i]);
    }
    return 0;
}
