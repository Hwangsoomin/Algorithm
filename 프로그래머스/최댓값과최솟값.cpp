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
string s="-1 -2 -3 -4";

string num, answer;
vector<pair<int, string>> arr;
int main(void) {
    for(int i=0; i<s.length(); i++) {
        if(s[i]==' ') continue;
        num += s[i];
        if(s[i+1]==' ' || i == (s.length()-1)) {
            int number = stoi(num);
            arr.push_back({number, num});
            num = "";
        }
    }
    sort(arr.begin(), arr.end());
    answer += arr[0].second;
    answer += ' ';
    answer += arr[arr.size()-1].second;
    
    cout << answer << endl;
    return 0;
}
