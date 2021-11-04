#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
using namespace std;
int r, c, a, b;
int main(void) {
	int n1 = 1, n2 = 1, n3 = 1, n4 = 1, n5 = 1;
	scanf("%d%d", &r, &c);
	scanf("%d%d", &a, &b);
	n1 = n3 * b;
	n5 = n4 * a;
	for (int i = 1; i <= r * a; i++) {
		for (int j = 1; j <= c * b; j++) {
			if (n2 == 1) {
				if (n3 % 2 == 1)printf("X");
				else printf(".");
				if (j == n1) {
					n3 += 1;
					n1 = n3 * b;
				}
			}
			else {
				if (n3 % 2 == 1)printf(".");
				else printf("X");
				if (j == n1) {
					n3 += 1;
					n1 = n3 * b;
				}
			}
		}
		printf("\n");
		n3 = 1;
		n1 = n3 * b;
		if (n5 == i) {
			n4 += 1;
			n5 = n4 * a;
			if (n2 == 1)n2 = 0;
			else n2 = 1;
		}
	}
	return 0;
}