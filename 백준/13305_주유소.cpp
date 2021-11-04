#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n;
long long sum, Min = 1e10, here;
long long oil[100005], arr[100005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) scanf("%lld", &oil[i]);
	for (int i = 1; i <= n; i++)scanf("%lld", &arr[i]);
	for (int i = 1; i <= n; i++){
		if (Min > arr[i]) {
			Min = arr[i];
			sum = sum + (oil[i]*Min);
		}
		else sum += (oil[i] * Min);
	}
	printf("%lld\n", sum);
	return 0;
}