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
vector<int> A={1,4,2};
vector<int> B={5,4,4};

int answer;
int main(void) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i=0; i<A.size(); i++) {
        answer += (A[i]*B[B.size()-i-1]);
    }
    
    cout << answer << endl;
    return 0;
}
