#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
#define ll long long
using namespace std;
vector<int> people={70, 50, 80, 50};
int limit=100;

int answer, l, r;
int main(void) {
    sort(people.begin(), people.end());
    l=0, r=people.size()-1;
    while(l<=r) {
        int sum = people[l]+people[r];
        if(sum==limit) {
            l+=1;
            r-=1;
        }
        else r-=1;
        answer+=1;
    }
    
    cout <<answer <<endl;
    return 0;
}
