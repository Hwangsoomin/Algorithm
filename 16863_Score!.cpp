#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int N, Hsum, Asum, si, bun;
int ansHs, ansHb, ansAs, ansAb;
char name;
string str;
int num;
vector < pair<pair<char, int>, pair<int, int>>> arr;
int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf(" %c %d %d:%d", &name, &num, &si, &bun);
		arr.push_back({ { name,num },{ si,bun } });
	}
	for (int i = 0; i < N; i++) {
		int hbun = arr[i].second.second;
		int hsi = arr[i].second.first;
		if (arr[i].first.first == 'H') {
			Hsum += arr[i].first.second;
		}
		else {
			Asum += arr[i].first.second;
		}
		if (Hsum > Asum) {
			if (i == N - 1) {
				int nbun = 0;
				int nsi = 32;
				if (nbun < hbun) {
					nbun += 60;
					nsi--;
				}
				ansHb += (nbun - hbun);
				ansHs += (nsi - hsi);
			}
			else {
				int nbun = arr[i + 1].second.second;
				int nsi = arr[i + 1].second.first;
				if (nbun < hbun) {
					nbun += 60;
					nsi--;
				}
				ansHb += (nbun - hbun);
				ansHs += (nsi - hsi);
			}
		}
		if (Asum > Hsum) {
			if (i == N - 1) {
				int nbun = 0;
				int nsi = 32;
				if (nbun < hbun) {
					nbun += 60;
					nsi--;
				}
				ansAb += (nbun - hbun);
				ansAs += (nsi - hsi);
			}
			else {
				int nbun = arr[i + 1].second.second;
				int nsi = arr[i + 1].second.first;
				if (nbun < hbun) {
					nbun += 60;
					nsi--;
				}
				ansAb += (nbun - hbun);
				ansAs += (nsi - hsi);
			}
		}
		if (ansHb >= 60) {
			int num = ansHb / 60;
			ansHb = ansHb % 60;
			ansHs += num;
		}
		if (ansAb >= 60) {
			int num = ansAb / 60;
			ansAb = ansAb % 60;
			ansAs += num;
		}
	}
	if (Hsum > Asum) {
		printf("H %d:%02d %d:%02d", ansHs, ansHb, ansAs, ansAb);
	}
	else {
		printf("A %d:%02d %d:%02d", ansHs, ansHb, ansAs, ansAb);
	}
	return 0;
}