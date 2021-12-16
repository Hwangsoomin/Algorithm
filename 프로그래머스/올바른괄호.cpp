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
string s="(()(";

bool answer = true;
stack<char> st;
int main(void) {
    for(int i=0; i<s.length(); i++) {
        char here = s[i];
        if(!answer) break;
        if(here==')') {
            if(st.empty()) answer = false;
            else st.pop();
        }
        else st.push('(');
    }
    if(!st.empty()) answer = false;
    
    cout << answer << endl;
    return 0;
}
