#include <iostream>
#include <string>
#include <vector>
using namespace std;
int getMaxCount(int n, int stair[], int dp[]) {
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    for(int i=3; i<=n; i++) {
        dp[i] = max((dp[i-3]+stair[i-1]+stair[i]), (dp[i-2]+stair[i]));
    }
    return dp[n];
}
int main(void) {
    int n, stair[305], dp[305] = {0,}, answer;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &stair[i]);
    }
    answer = getMaxCount(n, stair, dp);
    cout << answer << endl;
    return 0;
}
