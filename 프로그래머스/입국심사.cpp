#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
#define ll long long
using namespace std;
int n=6;
vector<int> times={7,10};

ll answer=1e20, l=1, r;
vector<int> arr;
ll cntPeo(ll num) {
    ll cnt=0;
    for(int i=0; i<arr.size(); i++) {
        cnt += (num/arr[i]);
    }
    
    return cnt;
}
int main(void) {
    arr=times;
    sort(arr.begin(), arr.end());
    r=arr[arr.size()-1]*n;
    while(l<=r) {
        ll mid = (l+r)/2;
        if(cntPeo(mid)>=n) {
            answer = min(answer, mid);
            r=mid-1;
        }
        else l=mid+1;
    }
    
    printf("%lld\n", answer);
    return 0;
}
