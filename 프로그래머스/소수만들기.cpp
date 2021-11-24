#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
using namespace std;
vector<int> nums={1,2,7,6,4};

int answer;
int arr[3005], check[55];
vector<int> nNums;
void go(int here, int sum, int cnt) {
    if(cnt==3) {
        if(!arr[sum]) answer += 1;
        return;
    }
    
    for(int i=here; i<nNums.size(); i++) {
        go(i+1, sum+nNums[i], cnt+1);
    }
}
int main(void) {
    nNums = nums;
    for(int i=2; i<=3000; i++) {
        if(arr[i]) continue;
        for(int j=i*2; j<=3000; j+=i) {
            arr[j]=1;
        }
    }
    go(0, 0, 0);
    
    printf("%d\n", answer);
    return 0;
}
