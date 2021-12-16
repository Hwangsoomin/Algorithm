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
vector<int> arr={1,1,3,3,0,1,1};

vector<int> answer;
int pre = -1;
int main(void) {
    for(int i=0; i<arr.size(); i++) {
        int num = arr[i];
        if(pre != num) {
            pre = num;
            answer.push_back(num);
        }
    }
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
    return 0;
}
