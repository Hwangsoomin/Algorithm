#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
long long n, rHA;
pair<long long, pair<long long, long long>> arr[123460];
bool flag = false;
int main(void) {
	long long t, a, h;
	scanf("%lld%lld", &n, &rHA);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &t, &a, &h);
		arr[i] = { t,{a,h} };
	}
	long long l = 1, r = 1e18, rmid = 0, mid = 0, HA = 0;
	while (l <= r) {
		rmid = (l + r) / 2;
		mid = rmid;
		flag = false;
		HA = rHA;
		for (int i = 1; i <= n; i++) {
			t = arr[i].first;
			a = arr[i].second.first;
			h = arr[i].second.second;
			if (t == 1) {//몬스터
				long long atck = h / HA;
				if (h%HA != 0)atck += 1;
				mid = mid - (a*(atck-1));
				if (mid <= 0) {
					flag = true;//용사 사망
					break;
				}
			}
			else {//포션
				HA = HA + a;
				if (mid + h <= rmid)mid = mid + h;
				else mid = rmid;
			}
		}
		if (flag == false) r = rmid - 1;
		else l = rmid + 1;
	}
	printf("%lld\n", l);
	return 0;
}