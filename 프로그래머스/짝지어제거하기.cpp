#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
#define ll long long
using namespace std;
string s="abbcggca";

stack<char> st;
int answer;
int main(void) {
    for(int i=0; i<s.length(); i++) {
            if(st.empty() || st.top()!=s[i]) st.push(s[i]);
            else st.pop();
        }
        
        if(st.empty()) answer=1;
    
    printf("%d\n", answer);
    return 0;
}
