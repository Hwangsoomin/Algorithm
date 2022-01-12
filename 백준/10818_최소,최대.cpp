#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<int> findMinMax(vector<int> arr) {
    vector<int> answer(2);
    sort(arr.begin(), arr.end());
    answer[0] = arr[0];
    answer[1] = arr[arr.size()-1];
    
    return answer;
}
int main(void) {
    int n;
    vector<int> arr, answer(2);
    scanf("%d", &n);
    arr.assign(n, 0);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    answer = findMinMax(arr);
    
    for(int i=0; i<answer.size(); i++) {
        printf("%d ", answer[i]);
    }
    return 0;
}
