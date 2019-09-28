#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int arr[3];
int main(void) {
	while (1) {
		scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
		sort(arr, arr + 3);
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)break;
		if (arr[2] * arr[2] == arr[0] * arr[0] + arr[1] * arr[1])printf("right\n");
		else printf("wrong\n");
	}
	return 0;
}