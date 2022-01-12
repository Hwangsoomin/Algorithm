#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
string s="xababcdcdababcdcd";
int checkString(string str, int len) {
    int here = 0;
    string pre = str.substr(here, len);
    string nstr = "";
    int cnt = 1;
    here += len;
    while(here<str.length()) {
        string next = str.substr(here, len);
        if(next==pre) {
            here += len;
            cnt += 1;
        }
        else {
            if(cnt==1) nstr += pre;
            else nstr = nstr + to_string(cnt) + pre;
            here += len;
            pre = next;
            cnt = 1;
        }
    }
    if(cnt==1) nstr += pre;
    else nstr = nstr + to_string(cnt) + pre;
    
    return nstr.length();
}
int main(void) {
    int answer = 1e9;
    for(int i=1; i<=s.length(); i++) {
        answer = min(answer, checkString(s, i));
    }
    
    cout << answer << endl;
    return 0;
}
