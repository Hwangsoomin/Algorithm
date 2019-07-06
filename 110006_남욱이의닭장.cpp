#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int t, n, m;
int main(void) {
	scanf("%d", &t);
	while (t--) {
		int sum = 0, rc = 0, c = 0;
		scanf("%d%d", &n, &m);
		sum = m * 2;
		c = sum - n;
		rc = m - c;
		printf("%d %d\n", c, rc);
	}
	return 0;
}