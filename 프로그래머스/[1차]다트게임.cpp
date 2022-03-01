#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    string dartResult = "1D2S3T*";
    vector<int> ans;
    int answer = 0;
    
    for(int i=0; i<dartResult.length(); i++) {
        int num = 0;
        char c1 = dartResult[i];
        if('0'<=c1 && c1<='9') num = c1 - '0';
        else {
            if(c1=='*') {
                ans[ans.size()-1] *= 2;
                ans[ans.size()-2] *= 2;
            }
            else {
                ans[ans.size()-1] *= -1;
            }
            if(i==dartResult.length()-1) break;
            num = dartResult[++i] - '0';
        }
        
        char c2 = dartResult[++i];
        if('0'<=c2 && c2<='9') {
            num = num*10 + (c2-'0');
            c2 = dartResult[++i];
        }
        if(c2=='D') num *= num;
        else if(c2=='T') num = num * num * num;
        
        ans.push_back(num);
    }
    for(int i=0; i<ans.size(); i++) {
        answer += ans[i];
    }
    
    cout << answer << endl;
    return 0;
}
