#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
using namespace std;
vector<int> numbers={1,2,3,4,6,7,8,0};
int answer;
int main(void) {
    sort(numbers.begin(), numbers.end());
    for(int i=0; i<numbers.size(); i++) {
        answer += numbers[i];
    }
    answer = 45-answer;
    
    printf("%d\n", answer);
    return 0;
}
