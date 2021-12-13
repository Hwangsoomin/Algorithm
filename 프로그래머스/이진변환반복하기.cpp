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
string s="1111111";

vector<int> answer;
int num, zeroCnt, cnt;
int main(void) {
    while(s!="1") {
        int zero = 0;
        int num = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='0') zero += 1;
        }
        num = s.length() - zero;
        s = "";
        while(num>0) {
            if(num%2==0) s = '0' + s;
            else s = '1' + s;
            num /= 2;
        }
        zeroCnt += zero;
        cnt += 1;
    }
    answer.push_back(cnt);
    answer.push_back(zeroCnt);
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
    return 0;
}
