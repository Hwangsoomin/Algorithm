#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int era[1000005];
int n, sum;
int main(void) {
	era[1] = 1;
	for (int i = 2; i < 200000; i++) {
		if (era[i])continue;
		for (int j = i * 2; j < 1000005; j += i) {
			if (era[j])continue;
			era[j] = 1;
		}
	}
	while (1) {
		sum = 0;
		scanf("%d", &n);
		if (n == 0)break;
		for (int i = n + 1; i <= 2 * n; i++) if (!era[i])sum++;
		printf("%d\n", sum);
	}
	return 0;
}