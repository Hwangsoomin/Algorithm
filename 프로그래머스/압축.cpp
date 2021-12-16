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
string msg="TOBEORNOTTOBEORTOBEORNOT";

map<string, int> strMap;
string str, pre;
int cnt = 26;
vector<int> answer;
int main(void) {
    for(int i=0; i<26; i++) {
        str = 'A'+i;
        strMap[str] = i+1;
    }
    for(int i=0; i<msg.length(); ) {
        int Index = i;;
        str = msg[i];
        while(strMap.find(str)!=strMap.end() && Index<msg.length()) {
            pre = str;
            str += msg[++Index];
        }
        answer.push_back(strMap[pre]);
        strMap[str] = ++cnt;
        i = Index;
    }
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
    return 0;
}
