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
string phone_number="01033334444";
int main(void) {
    string answer = "";
    for(int i=0; i<phone_number.length()-4; i++) answer += '*';
    for(int i=phone_number.length()-4; i<phone_number.size(); i++) answer += phone_number[i];
    
    cout << answer << endl;
    return 0;
}
