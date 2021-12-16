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
vector<vector<int>> arr={{1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1}};

vector<int> answer(2,0);
vector<vector<int>> narr;
void go(int r, int c, int cnt) {
    bool One = true, Zero = true;
    for(int i=r; i<r+cnt; i++) {
        for(int j=c; j<c+cnt; j++) {
            if(narr[i][j]==0) One = false;
            else if(narr[i][j]==1) Zero = false;
        }
    }
    if(Zero) {
        answer[0] += 1;
        return;
    }
    if(One) {
        answer[1] += 1;
        return;
    }
    go(r, c, cnt/2);
    go(r, c+cnt/2, cnt/2);
    go(r+cnt/2, c, cnt/2);
    go(r+cnt/2, c+cnt/2, cnt/2);
}
int main(void) {
    narr = arr;
    go(0,0,arr.size());
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
    return 0;
}
