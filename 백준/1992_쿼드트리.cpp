#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#define ll long long
using namespace std;
int n, arr[65][65], pre;
string ans;
int ch(int ns1, int ns2, int ncnt) {
	int np = arr[ns1][ns2];
	for (int i = ns1; i< ns1 + ncnt; i++) {
		for (int j = ns2; j < ns2 + ncnt; j++) {
			if (np != arr[i][j])return 1;
		}
	}
	return 0;
}
void go(int s1, int s2, int cnt) {
	if (ch(s1, s2, cnt)) {
		int mid = cnt / 2;
		printf("(");
		go(s1, s2, cnt / 2);
		go(s1, s2 + mid, cnt / 2);
		go(s1 + mid, s2, cnt / 2);
		go(s1 + mid, s2 + mid, cnt / 2);
		printf(")");
	}
	else printf("%d", arr[s1][s2]);
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	go(1, 1, n);
	return 0;
}