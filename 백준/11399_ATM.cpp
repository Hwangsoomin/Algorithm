#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int getMinimumTime(vector<int> P) {
    sort(P.begin(), P.end());
    int answer = 0, sum = 0;
    for(int i=0; i<P.size(); i++) {
        answer += (sum + P[i]);
        sum += P[i];
    }
    
    return answer;
}
int main(void) {
    int n, answer;
    vector<int> P;
    
    scanf("%d", &n);
    P.assign(n, 0);
    
    for(int i=0; i<n; i++) {
        scanf("%d", &P[i]);
    }
    
    answer = getMinimumTime(P);
    
    printf("%d\n", answer);
    return 0;
}
