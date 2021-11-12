#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
string str;
stack<char> st;
bool flag = false;
int main(void) {
    while(1) {
        while(!st.empty()) st.pop();
        getline(cin, str);
        if(str == ".") break;
        flag = false;
        for(int i=0; i<str.length(); i++) {
            char c = str[i];
            char topC = NULL;
            if(!st.empty()) topC = st.top();
            if(c == '[' || c == '(') st.push(c);
            else if(c == ']') {
                if(topC != '[') {
                    flag = true;
                    break;
                }
                if(topC == '[') st.pop();
            }
            else if(c ==')') {
                if(topC != '(') {
                    flag = true;
                    break;
                }
                if(topC == '(') st.pop();
            }
        }
        if(!st.empty()) flag = true;
        if(flag) cout << "no" << endl;
        else cout << "yes" << endl;
        
    }
    return 0;
}
