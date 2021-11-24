#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
using namespace std;
vector<int> scoville={1,2,3,9,10,12};
int K=7;

int answer;
priority_queue<int, vector<int>, greater<int>> q;
int main(void) {
    for(int i=0; i<scoville.size(); i++) {
        int num = scoville[i];
        q.push(num);
    }
    
    while(!q.empty()) {
        int n1=0, n2=0;
        if(!q.empty()) {
            n1=q.top();
            q.pop();
        }
        if(!q.empty()) {
            n2=q.top();
            q.pop();
        }
        
        if(n1>=K) break;
        if(!n2) {
            answer=-1;
            break;
        }
        int num = n1 + (n2*2);
        q.push(num);
        answer += 1;
    }
    
    printf("%d\n", answer);
    return 0;
}
