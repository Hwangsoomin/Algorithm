#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define MAX_NODE 5005
using namespace std;
int changeLocation(int n, int r, int c, int d, map<string, int> check) {
    pair<int, int> nd = {0, 0};
    if(d==0) nd = {1, 0};
    else if(d==1) nd = {1, 1};
    else if(d==2) nd = {0, 1};
    else if(d==3) nd = {-1, 1};
    else if(d==4) nd = {-1, 0};
    else if(d==5) nd = {-1, -1};
    else if(d==6) nd = {0, -1};
    else nd = {1, -1};
    
    int nr = r + nd.first;
    int nc = c + nd.second;
    int cnt = 0;
    string location = "";
    location += to_string(nr);
    location += ",";
    location += to_string(nc);
    while(nr>=1 && nr<=n && nc>=1 && nc<= n && check.find(location)==check.end()) {
        cnt += 1;
        location = "";
        nr = nr + nd.first;
        nc = nc + nd.second;
        location += to_string(nr);
        location += ",";
        location += to_string(nc);
    }
    
    return cnt;
}
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int answer = 0;
    map<string, int> check;
    
    for(int i=0; i<obstacles.size(); i++) {
        string location = "";
        int r = obstacles[i][0];
        int c = obstacles[i][1];
        location += to_string(r);
        location += ",";
        location += to_string(c);
        check[location] = 1;
    }
    for(int i=0; i<8; i++) {
        answer += changeLocation(n, r_q, c_q, i, check);
    }
    
    return answer;
}
int main(void) {
    int n, k, r_q, c_q, a, b;
    scanf("%d%d", &n, &k);
    vector<vector<int>> obstacles(k);
    scanf("%d%d", &r_q, &c_q);
    for(int i=0; i<k; i++) {
        scanf("%d%d", &a, &b);
        obstacles[i].push_back(a);
        obstacles[i].push_back(b);
    }
    int answer = queensAttack(n, k, r_q, c_q, obstacles);
    
    cout << answer << endl;
    return 0;
}
