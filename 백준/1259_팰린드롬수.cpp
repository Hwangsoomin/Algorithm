#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
string str;
bool flag = false;
int main(void) {
    while(1) {
        cin >> str;
        if(str == "0") break;
        flag = false;
        for(int i=0; i<str.length()/2; i++) {
            if(str[i] != str[str.length()-1-i]) flag = true;
        }
        if(flag) cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}
