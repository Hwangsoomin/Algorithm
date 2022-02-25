#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxScore;
vector<int> answer(1,-1);
bool isBetter(vector<int> lInfo) {
    for(int i=10; i>=0; i--) {
        if(lInfo[i] > answer[i]) return true;
        else if(lInfo[i] < answer[i]) return false;
    }
    return false;
}
void calcScore(vector<int> info, vector<int> lInfo) {
    int aScore = 0, lScore = 0;
    for(int i=0; i<11; i++) {
        if(lInfo[i]>info[i]) lScore += (10-i);
        else if(info[i]>0) aScore += (10-i);
    }
    
    int score = lScore - aScore;
    if(score>0 && score>=maxScore) {
        if(score==maxScore && !isBetter(lInfo)) return;
        
        maxScore = score;
        answer = lInfo;
    }
}
void getMaxScore(int idx, int cnt, vector<int> info, vector<int> lInfo) {
    if(cnt==0 || idx==11) {
        lInfo[10] += cnt;
        calcScore(info, lInfo);
        lInfo[10] -= cnt;
        return;
    }
    
    if(info[idx] < cnt) {
        lInfo[idx] += (info[idx] + 1);
        getMaxScore(idx+1, cnt - (info[idx]+1), info, lInfo);
        lInfo[idx] -= (info[idx] + 1);
    }
    
    getMaxScore(idx+1, cnt, info, lInfo);
}
int main(void) {
    int n = 5;
    vector<int> info = {2,1,1,1,0,0,0,0,0,0,0};
    vector<int> lInfo(11, 0);
    
    getMaxScore(0, n, info, lInfo);
    
    for(int i=0; i<answer.size(); i++) {
        cout << answer[i] << endl;
    }
    return 0;
}
