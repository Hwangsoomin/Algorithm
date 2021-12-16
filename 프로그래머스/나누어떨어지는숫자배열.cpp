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
vector<int> arr={5,9,7,10};
int divisor=5;

vector<int> answer;
int main(void) {
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]%divisor==0) answer.push_back(arr[i]);
    }
    if(!answer.size()) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
    return 0;
}
