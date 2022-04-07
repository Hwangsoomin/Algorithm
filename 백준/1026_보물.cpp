#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int getMinimumResult(int n, vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int answer = 0;
    
    for(int i=0; i<n; i++) {
        answer += (A[i]*B[n-1-i]);
    }
    
    return answer;
}
int main(void) {
    int n, answer;
    vector<int> A, B;
    
    scanf("%d", &n);
    A.assign(n, 0);
    B.assign(n, 0);
    
    for(int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &B[i]);
    }
    
    answer = getMinimumResult(n, A, B);
    
    printf("%d\n", answer);
    return 0;
}
