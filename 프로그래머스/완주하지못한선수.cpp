#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
using namespace std;
vector<string> participant={"leo","kiki","eden"};
vector<string> completion={"eden", "kiki"};

string answer;
multimap<string, int> m;
int sum, all;
int main(void) {
    for(int i=0; i<participant.size(); i++) {
        string peo = participant[i];
        m.insert({peo, i});
        all += i;
    }
    
    for(int i=0; i<completion.size(); i++) {
        string peo = completion[i];
        auto it = m.find(peo);
        sum += it->second;
        m.erase(it);
    }
    
    answer = participant[all-sum];
    
    cout<<answer<<endl;
    return 0;
}
