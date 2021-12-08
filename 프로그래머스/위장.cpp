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
vector<vector<string>> clothes={{"crowmask", "face"},{"bluesunglasses", "face"},{"smoky_makeup", "face"}};

int answer=1, cnt;
map<string, int> m;
int check[35];
vector<string> kind;
int main(void) {
    for(int i=0; i<clothes.size(); i++) {
        string name = clothes[i][0];
        string k = clothes[i][1];
        if(m.find(k)!=m.end()) {
            check[m[k]] += 1;
        }
        else {
            m[k] = m.size()+1;
            check[m[k]] += 1;
        }
    }
    cnt = m.size();
    for(int i=1; i<=cnt; i++) {
        answer *= (check[i]+1);
    }
    answer -= 1;
    
    cout << answer <<endl;
    return 0;
}
