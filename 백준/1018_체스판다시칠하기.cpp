#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int checkChessAndGetChangedCount(int n, int m, int number, char chess[][55]) {
    int cnt = 0;
    if(chess[n][m] != 'W' && number == 0) {
        cnt += 1;
        chess[n][m] = 'W';
    }
    else if(chess[n][m] != 'B' && number == 1) {
        cnt += 1;
        chess[n][m] = 'B';
    }
    
    for(int i=n; i<=n+7; i++) {
        for(int j=m; j<=m+7; j++) {
            if(i==n && j==m) continue;
            if(i==n) {
                if(chess[i][j-1] == 'W' && chess[i][j] != 'B') {
                    chess[i][j] = 'B';
                    cnt += 1;
                }
                else if(chess[i][j-1] == 'B' && chess[i][j] != 'W') {
                    chess[i][j] = 'W';
                    cnt += 1;
                }
            }
            else {
                if(chess[i-1][j] == 'W' && chess[i][j] != 'B') {
                    chess[i][j] = 'B';
                    cnt += 1;
                }
                else if(chess[i-1][j] == 'B' && chess[i][j] != 'W') {
                    chess[i][j] = 'W';
                    cnt += 1;
                }
            }
        }
    }
    
    return cnt;
}
int main(void) {
    int n, m, minAnswer = 2501;
    char chess[55][55], nChess[55][55];
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf(" %c", &chess[i][j]);
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(i+7 <=n && j+7 <= m) {
                for(int k=0; k<=1; k++) {
                    for(int x=1; x<=n; x++) {
                        for(int y=1; y<=m; y++) {
                            nChess[x][y] = chess[x][y];
                        }
                    }
                    minAnswer = min(minAnswer, checkChessAndGetChangedCount(i, j, k, nChess));
                }
            }
        }
    }
    
    printf("%d\n", minAnswer);
    return 0;
}
