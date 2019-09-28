#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int a, b, c, d, p;
int s1, s2;
int main(void) {
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &p);
	s1 = a * p;
	if (p > c) s2 = b + (p - c)*d;
	else s2 = b;
	if (s1 < s2)printf("%d\n", s1);
	else printf("%d\n", s2);
	return 0;
}