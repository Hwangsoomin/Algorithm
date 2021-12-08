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
vector<int> d={1,3,2,5,4};
int budget=9;

int answer, sum;
int main(void) {
    sort(d.begin(), d.end());
    for(int i=0; i<d.size(); i++) {
        if(sum+d[i]<=budget) {
            sum += d[i];
            answer += 1;
        }
    }
    
    cout << answer <<endl;
    return 0;
}
