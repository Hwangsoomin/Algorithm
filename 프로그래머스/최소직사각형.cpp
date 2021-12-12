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
vector<vector<int>> sizes={{60,50},{30,70},{60,30},{80,40}};

int answer, width, length;
int main(void) {
    for(int i=0; i<sizes.size(); i++) {
        if(sizes[i][0]<sizes[i][1]) swap(sizes[i][0], sizes[i][1]);
        width = max(width, sizes[i][0]);
        length = max(length, sizes[i][1]);
    }
    answer = width*length;
    
    cout << answer << endl;
    return 0;
}
