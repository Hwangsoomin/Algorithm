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
vector<string> words={"hello", "one", "even", "never", "now", "world", "draw"};
int n=2;

vector<int> answer;
map<string, int> m;
char pre;
int ans=1;
bool flag=false;
int main(void) {
    pre = words[0][words[0].length()-1];
    m[words[0]] = 1;
    for(int i=1; i<words.size(); i++) {
        ans += 1;
        string word = words[i];
        char here = word[0];
        if(here==pre) {
            if(m.find(word)!=m.end()) {
                flag=true;
                break;
            }
            else m[word] = i+1;
            pre = word[word.length()-1];
        }
        else {
            flag=true;
            break;
        }
    }
    if(ans==words.size() && !flag) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        if(ans%n==0) {
            answer.push_back(n);
            answer.push_back(ans/n);
        }
        else {
            answer.push_back(ans%n);
            answer.push_back(ans/n+1);
        }
    }
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
    return 0;
}
