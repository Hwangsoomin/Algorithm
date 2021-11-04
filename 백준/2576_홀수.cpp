#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#define ll long long
using namespace std;
int arr[10], Min = 1e9, sum;
int main(void) {
	for (int i = 1; i <= 7; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] % 2 != 0) {
			Min = min(Min, arr[i]);
			sum += arr[i];
		}
	}
	if (sum != 0) printf("%d\n%d\n", sum, Min);
	else printf("-1\n");
	return 0;
}