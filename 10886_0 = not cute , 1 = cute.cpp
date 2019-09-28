#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int n, ns, ys;
int main(void) {
	int a;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		if (a == 1)ys++;
		else ns++;
	}
	if (ys > ns)printf("Junhee is cute!\n");
	else printf("Junhee is not cute!\n");
	return 0;
}