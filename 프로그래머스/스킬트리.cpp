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
string skill="CBD";
vector<string> skill_trees={"C", "D", "CB", "BDA"};

int alpha[30], answer, check[30];
int main(void) {
    for(int i=0; i<skill.length(); i++) {
        char s = skill[i];
        alpha[s-'A'] = i+1;
    }
    for(int i=0; i<skill_trees.size(); i++) {
        string st = skill_trees[i];
        int num = 0;
        bool flag = false;
        for(int j=0; j<st.length(); j++) {
            if(alpha[st[j]-'A']==0) continue;
            check[st[j]-'A'] = ++num;
        }
        for(int j=0; j<st.length(); j++) {
            char s = st[j];
            if(check[s-'A'] != alpha[s-'A'] && check[s-'A']) flag = true;
        }
        if(!flag) answer += 1;
    }
    
    cout << answer << endl;
    return 0;
}
