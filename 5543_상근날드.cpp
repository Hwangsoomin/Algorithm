#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int b[3], a[2];
int main(void) {
	for (int i = 0; i < 3; i++)scanf("%d", &b[i]);
	sort(b, b + 3);
	for (int i = 0; i < 2; i++)scanf("%d", &a[i]);
	sort(a, a + 2);
	printf("%d\n", a[0] + b[0] - 50);
	return 0;
}