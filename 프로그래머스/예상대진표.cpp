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
int n=8, a=4, b=5;

vector<int> arr, arr1;
int answer, cnt;
int main(void) {
    if(a>b) {
        int temp = b;
        b=a;
        a=temp;
    }
    for(int i=1; i<=n; i++) arr.push_back(i);
    while(arr.size()!=0) {
        arr1 = arr;
        arr.clear();
        cnt += 1;
        int i=0;
        while(i<arr1.size()-1) {
            int f = arr1[i++];
            int s = arr1[i++];
            if(f==a && s==b) {
                answer = cnt;
                break;
            }
            
            if(f==a || f==b) arr.push_back(f);
            else if(s==a || s==b) arr.push_back(s);
            else arr.push_back(f);
        }
        if(answer!=0) break;
    }
    
    cout << answer <<endl;
    return 0;
}
