#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include<cmath>
#include <queue>
using namespace std;
bool checkBit(int N, int M) {
    bool flag = true;
    while(N--) {
        if(!(M&1)) {
            flag = false;
            break;
        }
        M = M >> 1;
    }
    
    return flag;
}
int main(void) {
    int test_case;
    int T, N, M;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M;
        bool flag = checkBit(N, M);
        if(flag) cout << '#' << test_case << ' ' << "ON" << endl;
        else cout << '#' << test_case << ' ' << "OFF" << endl;
    }
    return 0;
}
