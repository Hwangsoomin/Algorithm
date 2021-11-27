#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
using namespace std;
vector<int> numbers={1,1,1,1,1};
int target=3;

vector<int> arr;
int answer;
int check[25];
void dfs(int here, int sum, int t) {
    if(sum==t && here==arr.size()) {
        answer += 1;
        return;
    }
    if(here==arr.size()) return;
    if(!check[here]) {
        check[here] = 1;
        dfs(here+1, sum-arr[here], t);
        dfs(here+1, sum+arr[here], t);
        check[here]=0;
    }
}
int main(void) {
    arr=numbers;
    dfs(0, 0, target);
    
    printf("%d\n", answer);
    return 0;
}
