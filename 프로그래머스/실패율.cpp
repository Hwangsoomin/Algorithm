#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
#define ll long long
using namespace std;
int N=5;
vector<int> stages={2,1,2,6,2,4,3,3};

vector<int> answer;
int peo[200005], cPeo[200005];
double fail[200005];
vector<pair<int, double>> arr;

bool compare(pair<int, double> a, pair<int, double> b) {
    if(a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}
int main(void) {
    for(int i=0; i<stages.size(); i++) {
        int num = stages[i];
        for(int j=1; j<=num; j++) {
            if(j>N) continue;
            if(j==num) cPeo[j] +=1;
            peo[j] += 1;
        }
    }
    for(int i=1; i<=N; i++) {
        if(peo[i]==0) fail[i] = 0;
        else fail[i] = cPeo[i]/(peo[i]*1.0);
        arr.push_back({i, fail[i]});
    }
    sort(arr.begin(), arr.end(), compare);
    for(int i=0; i<arr.size(); i++) answer.push_back(arr[i].first);
    for(int i=0; i<answer.size(); i++) printf("%d\n", answer[i]);
    return 0;
}
