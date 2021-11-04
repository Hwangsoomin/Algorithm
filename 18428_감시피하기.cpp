#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, ans;
int arr[7][7], check[7][7], ncheck[7][7];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
vector<pair<int, int>> tea;
int ch() {
	for (int i = 0; i < tea.size(); i++) {
		for (int j = 0; j < 4; j++) {
			int r = tea[i].first;
			int c = tea[i].second;
			while (1) {
				r += dr[j];
				c += dc[j];
				if (r<1 || r>n || c<1 || c>n || check[r][c] == 1)break;
				if (arr[r][c] == 'S') return 1;
			}
		}
	}
	return 0;
}
int go(int r, int cnt) {
	if (cnt == 3) {
		ans += ch();
		if (!ch()) return 1;
		else return 0;
	}
	for (int i = r; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!check[i][j]) {
				if (arr[i][j] == 'X') {
					check[i][j] = 1;
					if (go(i, cnt + 1)) {//‰Î
						return 1;
					}
					check[i][j] = 0;
				}
			}
		}
	}
	return 0;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'T') {
				tea.push_back({ i,j });
			}
		}
	}
	if (!go(1, 0)) printf("NO\n");
	else printf("YES\n");
	return 0;
}