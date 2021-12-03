#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
#define ll long long
using namespace std;
vector<string> phone_book={"119", "97674223", "1195524421"};

bool compare(string a, string b) {
    return a.length() < b.length();
}
bool answer=true;
map<string, int> m;
int cnt, minLength=25;
int main(void) {
    sort(phone_book.begin(), phone_book.end(), compare);
    for(int i=0; i<phone_book.size(); i++) {
        int Length = phone_book[i].length();
        minLength = min(minLength, Length);
        if(Length==minLength) {
            m[phone_book[i]] = ++cnt;
            continue;
        }
        for(int j=minLength; j<=phone_book[i].size(); j++) {
            string str = phone_book[i].substr(0,j);
            if(m.find(str)!=m.end()){
                answer = false;
                break;
            }
            if(j==phone_book[i].size()) m[str] = ++cnt;
        }
        if(!answer) break;
    }
    
    cout << answer <<endl;
    return 0;
}
