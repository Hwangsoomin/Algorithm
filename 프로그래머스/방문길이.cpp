#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#define ll long long
using namespace std;
string dirs="ULURRDLLU";

int answer;
int check[15][15][5];
int r=5, c=5;
int main(void) {
    for(int i=0; i<dirs.length(); i++) {
        char dir = dirs[i];
        int nr = r, nc = c;
        int d = 0, nd = 0;
        if(dir=='U') {
            nr -= 1;
            d = 1;
            nd = 2;
        }
        else if(dir=='D') {
            nr += 1;
            d = 2;
            nd = 1;
        }
        else if(dir=='R') {
            nc += 1;
            d = 3;
            nd = 4;
        }
        else if(dir=='L') {
            nc -= 1;
            d = 4;
            nd = 3;
        }
        if(nr<0 || nr>10 || nc<0 || nc>10) continue;
        if(!check[nr][nc][nd]) {
            check[r][c][d] = 1;
            check[nr][nc][nd] = 1;
            answer += 1;
        }
        r = nr;
        c = nc;
    }
    
    cout << answer << endl;
    return 0;
}
