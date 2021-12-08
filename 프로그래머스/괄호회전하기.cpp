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
string s="}]()[{";

int answer;
bool flag = false;
string str;
void checkStr() {
    stack<char> st;
    for(int i=0; i<str.length(); i++) {
        if(str[i]==')' || str[i]=='}' || str[i]==']') {
            if(st.empty()) {
                flag = true;
                break;
            }
            else {
                char t = st.top();
                st.pop();
                if(str[i]==')') {
                    if(t!='('){
                        flag = true;
                        break;
                    }
                }
                else if(str[i]=='}') {
                    if(t!='{'){
                        flag = true;
                        break;
                    }
                }
                else if(str[i]==']') {
                    if(t!='['){
                        flag = true;
                        break;
                    }
                }
            }
        }
        else st.push(str[i]);
    }
    if(!st.empty()) flag = true;
}
int main(void) {
    for(int i=0; i<s.length(); i++) {
        str = s;
        flag = false;
        checkStr();
        if(!flag) answer += 1;
        
        str = s.substr(1);
        str += s[0];
        s=str;
    }
    
    cout << answer <<endl;
    return 0;
}
