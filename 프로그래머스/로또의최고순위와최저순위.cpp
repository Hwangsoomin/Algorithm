#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
vector<int> lottos, win_nums;
int a;

vector<int> answer;
int cnt, zeroCnt;
int checkRanking(int num) {
    if(num==6) return 1;
    else if(num==5) return 2;
    else if(num==4) return 3;
    else if(num==3) return 4;
    else if(num==2) return 5;
    else return 6;
}

int main(void) {
    for(int i=0; i<6; i++) {
        scanf("%d", &a);
        lottos.push_back(a);
    }
    for(int i=0; i<6; i++) {
        scanf("%d", &a);
        win_nums.push_back(a);
    }
    for(int i=0; i<lottos.size(); i++) {
        if(lottos[i]==0) zeroCnt+=1;
        for(int j=0; j<win_nums.size(); j++) {
            if(win_nums[j]==lottos[i]) cnt+=1;
        }
    }
    answer.push_back(checkRanking(cnt+zeroCnt));
    answer.push_back(checkRanking(cnt));
    
    for(int i=0; i<answer.size(); i++) {
        printf("%d\n", answer[i]);
    }
    return 0;
}
