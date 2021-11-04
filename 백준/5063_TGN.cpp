#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int n, r, e, c;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &r, &e, &c);
		if (r < e - c)printf("advertise\n");
		else if (r == e - c)printf("does not matter\n");
		else printf("do not advertise\n");
	}
	return 0;
}