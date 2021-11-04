#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
long long n, sum, pre;
char arr[5000005];
bool flag = false;
int main(void) {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		if ('0' <= arr[i] && arr[i] <= '9') {
			pre = (pre*10);
			pre += (arr[i] - '0');//여기까지 현재 숫자
		}
		else {
			if (i == n - 1)flag = true;
			sum += pre;
			pre = 0;
		}
	}
	if (!flag)sum += pre;
	if (sum == 0)printf("0\n");
	else printf("%lld\n", sum);
	return 0;
}