#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string s;
bool checkP(string str) {
    bool ans = true;
    for(int i=0; i<str.length()/2; i++) {
        if(str[i]!=str[str.length()-1-i]) {
            ans = false;
            break;
        }
    }
    
    return ans;
}
int main(void) {
    int answer = 0;
    cin >> s;
    for(int i=0; i<s.length(); i++) {
        string str = s.substr(i);
        bool ans = checkP(str);
        if(ans) {
            answer = s.length() + i;
            break;
        }
    }
    
    cout << answer << endl;
    return 0;
}
