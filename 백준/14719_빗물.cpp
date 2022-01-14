#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
using namespace std;
pair<int, int> LeftRightMax(vector<int> h, int index) {
    int Left = 0, Right = 0;
    for(int i=0; i<index; i++) {
        Left = max(Left, h[i]);
    }
    for(int i=index+1; i<h.size(); i++) {
        Right = max(Right, h[i]);
    }
    
    return {Left, Right};
}
int calRain(vector<int> h) {
    int answer = 0;
    for(int i=0; i<h.size(); i++) {
        pair<int, int> result = LeftRightMax(h, i);
        if(min(result.first, result.second) - h[i]<0) continue;
        answer += min(result.first, result.second) - h[i];
    }
    
    return answer;
}
int main(void) {
    int H, W, answer;
    vector<int> h;
    scanf("%d%d", &H, &W);
    h.assign(W, 0);
    
    for(int i=0; i<W; i++) {
        scanf("%d", &h[i]);
    }
    answer = calRain(h);
    printf("%d\n", answer);
    return 0;
}
