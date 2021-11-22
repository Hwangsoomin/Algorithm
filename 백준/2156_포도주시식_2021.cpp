#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int n;
int arr[10005], dp[10005];
int main(void) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
    }
    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    dp[3] = max(dp[2], max(arr[1]+arr[3], arr[2]+arr[3]));
    for(int i=4; i<=n; i++) {
        dp[i] = max(dp[i-1], max(dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]));
    }
    printf("%d\n", dp[n]);
    return 0;
}
