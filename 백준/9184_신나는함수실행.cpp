#include <iostream>
#include <string>
#include <vector>
using namespace std;
int dp[25][25][25];
int go(int a, int b, int c) {
    if(a<=0 || b<=0 || c<=0) return 1;
    else if(a>20 || b>20 || c>20) return go(20, 20, 20);
    
    if(dp[a][b][c] != -1) return dp[a][b][c];
    
    if(a<b && b<c) return dp[a][b][c] = go(a, b, c-1) + go(a, b-1, c-1) - go(a, b-1, c);
    else return dp[a][b][c] = go(a-1, b, c) + go(a-1, b-1, c) + go(a-1, b, c-1) - go(a-1, b-1, c-1);
}
int main(void) {
    int a, b, c;
    for(int i=0; i<25; i++) {
        for(int j=0; j<25; j++) {
            for(int k=0; k<25; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    while(1) {
        scanf("%d%d%d", &a, &b, &c);
        if(a==-1&&b==-1&&c==-1) break;
        
        printf("w(%d, %d, %d) = %d\n", a, b, c, go(a, b, c));
    }
    return 0;
}
