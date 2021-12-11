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
vector<vector<int>> routes={{-20,-15},{-14,-5},{-18,-13},{-5,-3}};

int answer, cnt=1, pre, sum;
int main(void) {
    sort(routes.begin(), routes.end());
    pre = routes[0][1];
    for(int i=1; i<routes.size(); i++) {
        int start = routes[i][0];
        int end = routes[i][1];
        if(pre>=start) {
            if(end<pre) pre=end;
            cnt += 1;
        }
        else {
            sum += cnt;
            answer += 1;
            pre = end;
            cnt = 1;
        }
    }
    if(sum<routes.size()) answer += 1;
    
    cout << answer << endl;
    return 0;
}
