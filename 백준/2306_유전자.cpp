#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
string str;
int Max;
int dna[505][505];
int go(int l, int r) {
	if (dna[l][r] != -1)return dna[l][r];
	if (l == r) {
		dna[l][r] = 0;
		return dna[l][r];
	}
	if (l + 1 == r) {
		if (str[l] == 'a' && str[r] == 't' || str[l] == 'g' && str[r] == 'c') dna[l][r] = 2;
		else dna[l][r] = 0;
		return dna[l][r];
	}
	for (int i = 0; i < (r - l); i++) {
		dna[l][r] = max(dna[l][r], go(l, l + i) + go(l + i + 1, r));
	}
	if (str[l] == 'a' && str[r] == 't' || str[l] == 'g' && str[r] == 'c') dna[l][r] = max(dna[l][r], 2 + go(l + 1, r - 1));
	else dna[l][r] = max(dna[l][r], go(l + 1, r - 1));
	return dna[l][r];
}
int main(void) {
	cin >> str;
	for (int i = 0; i < 505; i++) {
		for (int j = 0; j < 505; j++)dna[i][j] = -1;
	}
	go(0, str.size() - 1);
	printf("%d\n", dna[0][str.size()-1]);
	return 0;
}