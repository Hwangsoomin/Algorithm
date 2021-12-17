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
int n=15;

int answer;
string go(int num) {
    string str = "";
    while(num > 0) {
        if(num%2==0) str += '0';
        else str += '1';
        num /= 2;
    }
    return str;
}
int check(string str) {
    int One = 0;
    for(int i=0; i<str.length(); i++) {
        if(str[i]=='1') One += 1;
    }
    return One;
}
int main(void) {
    answer = n;
    string str = go(n);
    int nCheck = check(str);
    while(1) {
        answer += 1;
        str = go(answer);
        int numCheck = check(str);
        if(numCheck == nCheck) break;
    }
    
    cout << answer << endl;
    return 0;
}
