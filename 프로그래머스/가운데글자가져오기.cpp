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
string s="qwer";

string answer;
int main(void) {
    if(s.length()%2==0) {
        for(int i=(s.length()/2-1); i<=s.length()/2; i++) answer += s[i];
    }
    else answer = s[s.length()/2];
    
    cout << answer << endl;
    return 0;
}
