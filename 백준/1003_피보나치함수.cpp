#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
int t, n;
int fb[45] = { 1,1 };
int fibo(int num) {
	if (fb[num] != 0)return fb[num];
	else return fb[num] = fibo(num - 1) + fibo(num - 2);
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n == 0)printf("1 0\n");
		else if (n == 1)printf("0 1\n");
		else {
			fibo(n);
			printf("%d %d\n", fb[n - 2], fb[n - 1]);
		}
	}
	return 0;
}