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
vector<string> strings={"abce", "abcd", "cdx"};
int n=2;

vector<string> answer;
map<char, int> m;
vector<pair<string, int>> arr[55];
vector<pair<char, int>> arr1;
int cnt;
int main(void) {
    for(int i=0; i<strings.size(); i++) {
        string str = strings[i];
        char s = str[n];
        if(m.find(s)==m.end()) {
            m[s] = ++cnt;
            arr1.push_back({s, cnt});
        }
        arr[m[s]].push_back({str, i});
    }
    sort(arr1.begin(), arr1.end());
    for(int i=1; i<=cnt; i++) sort(arr[i].begin(), arr[i].end());
    
    for(int i=0; i<arr1.size(); i++) {
        int here = arr1[i].second;
        for(int j=0; j<arr[here].size(); j++) {
            answer.push_back(arr[here][j].first);
        }
    }
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
    return 0;
}
