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
int cacheSize=0;
vector<string> cities={"Jeju", "Pangyo", "Seoul", "NewYork", "LA"};

int answer;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq, npq;
int main(void) {
    for(int i=0; i<cities.size(); i++) {
        for(int j=0; j<cities[i].length(); j++) {
            cities[i][j] = tolower(cities[i][j]);
        }
    }
    
    for(int i=0; i<cities.size(); i++) {
        string city = cities[i];
        bool flag = false;
        while(!pq.empty()) {
            pair<int, string> here = pq.top();
            pq.pop();
            if(here.second == city) {
                flag = true;
                npq.push({i+1, city});
                answer += 1;
            }
            else npq.push(here);
        }
        while(!npq.empty()) {
            pq.push(npq.top());
            npq.pop();
        }
        if(!flag) {
            if(!pq.empty() && pq.size()==cacheSize)pq.pop();
            if(pq.size()<cacheSize)pq.push({i+1, city});
            answer += 5;
        }
    }
    
    cout << answer << endl;
    return 0;
}
