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
int h, w, n, t;
int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &h, &w, &n);
		int num = n / h;
		int num1 = n % h;
		int ans = 0;
		if (num1 == 0)ans = h * 100 + num;
		else ans = num1 * 100 + num + 1; 
		printf("%d\n", ans);
	}
	return 0;
}