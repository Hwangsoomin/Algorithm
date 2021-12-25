#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <deque>
#define ll long long
using namespace std;
vector<string> seoul={"Jane", "Kim"};

string answer;
int main(void) {
    for(int i=0; i<seoul.size(); i++) {
        string str = seoul[i];
        if(str=="Kim") {
            answer = "김서방은 " + to_string(i) + "에 있다";
            break;
        }
    }
    
    cout << answer << endl;
    return 0;
}
