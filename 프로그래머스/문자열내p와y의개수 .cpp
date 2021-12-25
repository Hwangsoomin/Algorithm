#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <deque>
#define ll long long
using namespace std;
string s="pPoooyYy";

int cntP, cntY;
bool answer;
int main(void) {
    for(int i=0; i<s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='p') cntP += 1;
        else if(s[i]=='y') cntY += 1;
    }
    if(cntP==cntY) answer = true;
    
    cout << answer << endl;
    return 0;
}
