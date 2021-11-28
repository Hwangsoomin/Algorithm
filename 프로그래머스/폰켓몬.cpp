#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
#define ll long long
using namespace std;
vector<int> nums={3,3,3,2,2,2};

int answer, cnt;
int check[200005];
int main(void) {
    for(int i=0; i<nums.size(); i++) {
        int num = nums[i];
        if(!check[num]) {
            check[num]=1;
            cnt+=1;
        }
    }
    
    if(nums.size()/2<cnt) answer=nums.size()/2;
    else answer=cnt;
    
    printf("%d\n", answer);
    return 0;
}
