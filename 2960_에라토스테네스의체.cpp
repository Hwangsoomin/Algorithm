#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<map>
#define ll long long
using namespace std;
int n, k, num, ans;
int check[1005];
int main(void) {
	scanf("%d%d", &n, &k);
	for (int i = 2; i <= n; i++) {
			for (int j = i; j <= n; j+=i) {
				if(!check[j]){
				check[j] = 1;
				num += 1;
				if (num == k) {
					ans = j;
					break;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}