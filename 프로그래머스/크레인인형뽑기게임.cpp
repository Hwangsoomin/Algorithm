#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
using namespace std;
vector<vector<int>> board={{0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1}};
vector<int> moves={1,5,3,5,1,2,1,4};

vector<int> nboard[35];
stack<int> st;
int answer;
int main(void) {
    for(int i=board.size()-1; i>=0; i--) {
        for(int j=0; j<board[i].size(); j++) {
            if(board[i][j]!=0) nboard[j+1].push_back(board[i][j]);
        }
    }
    
    for(int i=0; i<moves.size(); i++) {
        int here = moves[i];
        int num = 0;
        if(nboard[here].size()!=0) {
            num = nboard[here][nboard[here].size()-1];
            nboard[here].pop_back();
        }
        if(num!=0) {
            int top = 0;
            if(!st.empty()) top = st.top();
            if(top==num) {
                answer += 2;
                st.pop();
            }
            else st.push(num);
        }
    }
    
    printf("%d\n", answer);
    return 0;
}
