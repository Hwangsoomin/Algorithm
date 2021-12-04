#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
#define ll long long
using namespace std;
vector<int> numbers={2,1,3,4,1};

map<int, int> m;
int cnt;
vector<int> answer;
int main(void) {
    for(int i=0; i<numbers.size(); i++) {
        for(int j=i+1; j<numbers.size(); j++) {
            int sum = numbers[i] + numbers[j];
            if(m.find(sum)!=m.end()) continue;
            m[sum] = ++cnt;
            answer.push_back(sum);
        }
    }
    sort(answer.begin(), answer.end());
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] <<endl;
    return 0;
}
