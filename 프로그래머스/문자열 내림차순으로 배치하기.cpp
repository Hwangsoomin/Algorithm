#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    string s = "ZbcdWRWWefag";
    string answer = "";
    vector<char> small, big;
    
    for(int i=0; i<s.length(); i++) {
        if('a'<=s[i] && s[i]<='z') small.push_back(s[i]);
        else big.push_back(s[i]);
    }
    sort(small.begin(), small.end());
    sort(big.begin(), big.end());
    for(int i=small.size()-1; i>=0; i--) {
        answer += small[i];
    }
    for(int i=big.size()-1; i>=0; i--) {
        answer += big[i];
    }
    
    cout << answer << endl;
    return 0;
}
