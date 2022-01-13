#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
using namespace std;
string p="()))((()";
pair<string, string> divideStr(string str) {
    int bracketL = 0;
    int bracketR = 0;
    string u = "", v = "";
    for(int i=0; i<str.length(); i++) {
        if(bracketL==bracketR && bracketL!=0){
            v += str[i];
        }
        else {
            if(str[i]=='(') bracketL += 1;
            else bracketR += 1;
            u += str[i];
        }
    }
    
    return {u, v};
}
bool checkU(string str) {
    stack<char> st;
    bool flag = true;
    for(int i=0; i<str.length(); i++) {
        if(str[i]=='(') st.push('(');
        else {
            if(st.empty()){
                flag = false;
                break;
            }
            else st.pop();
        }
    }
    if(!st.empty()) flag = false;
    
    return flag;
}
string reverseU(string str) {
    string newU = "";
    for(int i=1; i<str.length()-1; i++) {
        if(str[i]=='(') newU += ')';
        else newU += '(';
    }
    
    return newU;
}
string checkP(string str) {
    pair<string, string> result = divideStr(str);
    if(checkU(result.first)) {
        if(result.second.length()==0) return result.first + "";
        else return result.first + checkP(result.second);
    }
    else {
        string nstr = "(";
        if(result.second.length()==0) str += "";
        else nstr += checkP(result.second);
        nstr += ")";
        return nstr += reverseU(result.first);
    }
}
int main(void) {
    string answer = checkP(p);
    
    cout << answer << endl;
    return 0;
}
