#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
string str, answer;
int main(void) {
    cin >> str;
    for(int i=0; i<str.length(); i++) {
        if('A'<=str[i] && str[i]<='Z') answer += str[i];
    }
    cout << answer << endl;
    return 0;
}
