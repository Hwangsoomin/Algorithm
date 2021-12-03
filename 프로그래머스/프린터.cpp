#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
#define ll long long
using namespace std;
vector<int> priorities={2, 1, 3, 2};
int location=2;

vector<int> np;
queue<pair<int,int>> q;
int here=1, answer, cnt;
int main(void) {
    np = priorities;
    sort(np.begin(), np.end());
    here = np.size()-1;
    for(int i=0; i<priorities.size(); i++) q.push({priorities[i], i});
    while(!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        if(t.first!=np[here]) q.push({t.first, t.second});
        else {
            cnt+=1;
            here-=1;
            if(t.second==location) {
                answer = cnt;
                break;
            }
        }
    }
    
    cout << answer << endl;
    return 0;
}
