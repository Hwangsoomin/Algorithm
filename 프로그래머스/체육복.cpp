#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
using namespace std;
int n=3;
vector<int> lost={3};
vector<int> reserve={1};

int answer;
int check[35];
int main(void) {
    for(int i=1; i<=n; i++) {
        check[i]=1;
    }
    for(int i=0; i<lost.size(); i++) {
        int peo = lost[i];
        check[peo] -= 1;
    }
    for(int i=0; i<reserve.size(); i++) {
        int peo = reserve[i];
        check[peo] += 1;
    }
    for(int i=n; i>=1; i--) {
        if(i==n) {
            if(check[i]==0) {
                if(check[i-1]==2) {
                    check[i-1] -= 1;
                    check[i] = 1;
                }
            }
        }
        else if(i==1) {
            if(check[i]==0) {
                if(check[i+1]==2) {
                    check[i+1] -= 1;
                    check[i] = 1;
                }
            }
        }
        else {
            if(check[i]==0) {
                if(check[i+1]==2) {
                    check[i+1] -= 1;
                    check[i] = 1;
                }
                else if(check[i-1]==2) {
                    check[i-1] -= 1;
                    check[i] = 1;
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(check[i]>=1) answer += 1;
    }
    printf("%d\n", answer);
    return 0;
}
