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
vector<int> prices={1,2,3,2,3};

vector<int> answer;
stack<pair<int,int>> st;
int check[100005];
int main(void) {
    for(int i=0; i<prices.size(); i++) {
        int here = prices[i];
        if(st.empty())st.push({here, i+1});
        else {
            pair<int, int> pre = st.top();
            if(pre.first<=here) st.push({here, i+1});
            else {
                while(pre.first>here) {
                    check[pre.second] = (i+1)-pre.second;
                    st.pop();
                    if(st.empty()) break;
                    pre = st.top();
                }
                st.push({here, i+1});
            }
        }
    }
    pair<int, int> pre = st.top();
    while(!st.empty()) {
        pair<int, int> here = st.top();
        st.pop();
        check[here.second] = pre.second - here.second;
    }
    for(int i=1; i<=prices.size(); i++) answer.push_back(check[i]);
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
    return 0;
}
