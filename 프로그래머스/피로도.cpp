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
vector<vector<int>> dungeons={{80,20},{50,40},{30,10}};
int k=80;

int check[10];
int answer;
vector<vector<int>> arr;
void go(int sum, int cnt) {
    answer = max(answer, cnt);
    for(int i=0; i<arr.size(); i++) {
        int necessary = arr[i][0];
        int cost = arr[i][1];
        if(!check[i] && sum>=necessary) {
            check[i] = 1;
            go(sum-cost, cnt+1);
            check[i] = 0;
        }
    }
}
int main(void) {
    arr = dungeons;
    go(k, 0);
    
    cout << answer <<endl;
    return 0;
}
