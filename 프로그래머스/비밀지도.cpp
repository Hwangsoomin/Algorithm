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
int n=5;
vector<int> arr1={9,20,28,18,11}, arr2={30,1,21,17,28};

int here;
int narr1[20][20], narr2[20][20];
vector<string> answer;
int main(void) {
    for(int i=0; i<arr1.size(); i++) {
        int num = arr1[i];
        here = n;
        while(num>0) {
            if(num%2!=0) narr1[i+1][here]= 1;
            else narr1[i+1][here] = 0;
            here -= 1;
            num /= 2;
        }
        while(num>0) {
            narr1[i+1][here] = 0;
            here -= 1;
        }
    }
    for(int i=0; i<arr2.size(); i++) {
        int num = arr2[i];
        here = n;
        while(num>0) {
            if(num%2!=0) narr2[i+1][here]= 1;
            else narr2[i+1][here] = 0;
            here -= 1;
            num /= 2;
        }
        while(num>0) {
            narr2[i+1][here] = 0;
            here -= 1;
        }
    }
    for(int i=1; i<= arr1.size(); i++) {
        string str = "";
        for(int j=1; j<=n; j++) {
            if(narr1[i][j]==1 || narr2[i][j]==1) str += '#';
            else str += ' ';
        }
        answer.push_back(str);
    }
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
    return 0;
}
