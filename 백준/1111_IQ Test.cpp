#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, a, b;
int arr[55];
bool flag = false;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
	if (n == 1) {
		printf("A\n");
		return 0;
	}
	if (n == 2) {
		if (arr[1] == arr[2]) printf("%d\n", arr[1]);
		else printf("A\n");
		return 0;
	}
	if (arr[2] - arr[1] == 0)a = 0;
	else a = (arr[3] - arr[2]) / (arr[2] - arr[1]);
	b = arr[2] - a * arr[1];
	for (int i = 1; i <= n - 1; i++) {
		if (a*arr[i] + b != arr[i + 1])flag = true;
	}
	if(!flag) printf("%d\n", arr[n] * a + b);
	else printf("B\n");
	return 0;
}