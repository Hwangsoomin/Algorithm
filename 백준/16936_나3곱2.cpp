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
#define MAX 1000000000
using namespace std;
int n;
ll arr[105], ans[105];
bool flag = false;
map<ll, int> m;
void go(ll num, int cnt) {
	if (cnt == n) {
		flag = true;
		for (int i = 1; i <= cnt; i++)printf("%lld ", ans[i]);
		return;
	}
	if (num % 3 == 0) {
		if (m.find(num / 3) != m.end()) {
			ans[cnt + 1] = (num / 3);
			go(num / 3, cnt + 1);
		}
	}
	if (m.find(num * 2) != m.end()) {
		ans[cnt + 1] = (num * 2);
		go(num * 2, cnt + 1);
	}
	return;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
		m[arr[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		memset(ans, 0, sizeof(ans));
		flag = false;
		ans[1] = arr[i];
		go(arr[i], 1);
		if (flag)break;
	}
	return 0;
}