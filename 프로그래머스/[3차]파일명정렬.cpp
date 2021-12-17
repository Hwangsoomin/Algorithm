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
vector<string> files={"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"};

vector<string> answer;
map<string, int> m;
vector<pair<string, int>> arr;
vector<pair<int, int>> arr1[1005];
int cnt;
int main(void) {
    for(int i=0; i<files.size(); i++) {
        string file = files[i];
        string head = "";
        string number = "";
        int Index=0;
        while(1) {
            if(0<=file[Index]-'0' && (file[Index]-'0')<=9) break;
            head += tolower(file[Index]);
            Index += 1;
        }
        while(0<=file[Index]-'0' && (file[Index]-'0')<=9) {
            number += file[Index];
            Index += 1;
        }
        int num = stoi(number);
        if(m.find(head)==m.end()) {
            m[head] = ++cnt;
            arr.push_back({head, cnt});
        }
        int mapNum = m[head];
        arr1[mapNum].push_back({num, i+1});
    }
    sort(arr.begin(), arr.end());
    for(int i=1; i<=cnt; i++) sort(arr1[i].begin(), arr1[i].end());
    
    for(int i=0; i<arr.size(); i++) {
        pair<string, int> here = arr[i];
        for(int j=0; j<arr1[here.second].size(); j++) {
            int num = arr1[here.second][j].second;
            answer.push_back(files[num-1]);
        }
    }
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
    return 0;
}
