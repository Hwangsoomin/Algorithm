#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
int sum, a, x, y;
int main(void) {
	for (int i = 1; i <= 4; i++) {
		scanf("%d", &a);
		sum += a;
	}
	x = sum / 60;
	y = sum % 60;
	printf("%d\n%d\n", x, y);
	return 0;
}