#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
long long num;
int arr[25], nn, pre;
bool flag = false;
int main(void) {
	scanf("%lld", &num);
	while (num > 0) {
		arr[nn++] = num % 10;
		num /= 10;
	}
	pre = arr[1] - arr[0];
	for (int i = 1; i < nn - 1; i++) {
		int aa = arr[i + 1] - arr[i];
		if (pre != aa) {
			flag = true;
			break;
		}
	}
	if (flag) printf("흥칫뿡!! <(￣ ﹌ ￣)>\n");
	else printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!\n");
	return 0;
}