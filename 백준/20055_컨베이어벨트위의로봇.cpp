#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
using namespace std;
int n, k;
pair<vector<int>, vector<int>> moveBelt(vector<int> a, vector<int> robot) {
    int lastBelt = a[a.size()-1];
    vector<int> nRobot;
    for(int i=a.size()-1; i>=1; i--) {
        a[i] = a[i-1];
    }
    a[0] = lastBelt;
    
    for(int i=0; i<robot.size(); i++) {
        if(robot[i]==n-1) continue;
        else nRobot.push_back(robot[i]+1);
    }
    return {a, nRobot};
}
pair<vector<int>, vector<int>> moveRobot(vector<int> a, vector<int> robot) {
    vector<int> nRobot;
    for(int i=0; i<robot.size(); i++) {
        int r = robot[i]; // 현재 로봇 위치
        if(r==n-1) continue;
        else {
            if(a[r+1]>=1 && (nRobot.size()==0 || nRobot[nRobot.size()-1]!=(r+1))) {
                nRobot.push_back(r+1);
                a[r+1] -= 1;
            }
            else {
                nRobot.push_back(r);
            }
        }
    }
    return {a, nRobot};
}
int checkZero(vector<int> a) {
    int cnt = 0;
    for(int i=0; i<a.size(); i++) {
        if(a[i]==0) cnt += 1;
    }
    
    return cnt;
}
int main(void) {
    int answer = 0;
    vector<int> a, robot;
    scanf("%d%d", &n, &k);
    a.assign(n*2, 0);
    for(int i=0; i<n*2; i++) {
        scanf("%d", &a[i]);
    }
    while(1) {
        answer += 1;
        pair<vector<int>, vector<int>> result = moveBelt(a, robot);
        a = result.first;
        robot = result.second;
        
        result = moveRobot(a, robot);
        a = result.first;
        robot = result.second;
        if(a[0]>=1) {
            robot.push_back(0);
            a[0] -= 1;
        }
        if(checkZero(a)>=k) break;
    }
    
    printf("%d\n", answer);
    return 0;
}
