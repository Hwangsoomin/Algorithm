#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int l, a, b, c, d, s1, s2;
int main(void) {
	scanf("%d%d%d%d%d", &l, &a, &b, &c, &d);
	s1 = a / c;
	s2 = b / d;
	if (a%c > 0)s1++;
	if (b%d > 0)s2++;
	if (s1 > s2)printf("%d\n", l - s1);
	else printf("%d\n", l - s2);
	return 0;
}