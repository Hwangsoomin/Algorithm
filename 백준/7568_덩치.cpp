#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int n, x, y;
pair<int, int> arr[55];
int answer[55];
int main(void) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d%d", &x, &y);
        arr[i] = {x, y};
    }
    for(int i=1; i<=n; i++) {
        int cnt = 0;
        for(int j=1; j<=n; j++) {
            if(arr[i].first<arr[j].first && arr[i].second<arr[j].second) cnt+=1;
        }
        answer[i] = cnt+1;
    }
    for(int i=1; i<=n; i++) printf("%d ", answer[i]);
    return 0;
}
