#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, num1, num2;
int card1[500005], card2[500005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &card1[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)scanf("%d", &card2[i]);
	sort(card1 + 1, card1 + n + 1);
	for (int i = 1; i <= m; i++) {
		int l = 1, r = n, mid = 0;
		num1 = 1e9, num2 = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (card1[mid] == card2[i]) {
				num1 = min(num1, mid);
			}
			if (card1[mid] >= card2[i]) r = mid - 1;
			else l = mid + 1;
		}
		l = 1, r = n, mid = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (card1[mid] == card2[i])num2 = max(num2, mid);
			if (card1[mid] > card2[i]) r = mid - 1;
			else l = mid + 1;
		}
		if(num1!=1e9&&num2!=0) printf("%d ", num2 - num1 + 1);
		else printf("0 ");
	}
	return 0;
}