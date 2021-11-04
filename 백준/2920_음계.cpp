#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int ans[8] = { 1,2,3,4,5,6,7,8 };
int num[8];
int cnt, cnt1;
int main(void) {
	for (int i = 0; i < 8; i++) {
		scanf("%d", &num[i]);
		if (num[i] == ans[i]) {
			cnt++;
		}
		else if (num[i] == ans[7 - i]) {
			cnt1++;
		}
	}
	if (cnt == 8) {
		printf("ascending");
	}
	else if (cnt1 == 8) {
		printf("descending");
	}
	else {
		printf("mixed");
	}
	return 0;
}