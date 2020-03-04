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
int n, cnt = 1, nn = 1;
int main(void) {
	scanf("%d", &n);
	if (n % 2 == 0 || n % 5 == 0) {
		printf("-1\n");
		return 0;
	}
	while (nn % n != 0) {
		nn %= n;
		nn = nn * 10 + 1;
		cnt += 1;
	}
	printf("%d\n", cnt);
	return 0;
}