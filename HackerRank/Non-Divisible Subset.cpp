#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_NODE 5005
using namespace std;
int* modArray(int num[], int k, vector<int> s) {
    for(int i=0; i<s.size(); i++) {
        int n = s[i];
        num[n%k] += 1;
    }
    
    return num;
}
int nonDivisibleSubset(int k, vector<int> s) {
    int answer = 0;
    int num[100] = {0,};
    int* arr = modArray(num, k, s);
    answer += min(arr[0], 1);
    if(k%2==0) answer += min(arr[k/2], 1);
    for(int i=1; i<=k/2; i++) {
        if(i != (k-i)) answer += max(arr[i], arr[k-i]);
    }
    
    return answer;
}

int main(void) {
    int n, k, a;
    vector<int> s;
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a);
        s.push_back(a);
    }
    
    int answer = nonDivisibleSubset(k, s);
    
    cout << answer << endl;
    return 0;
}
