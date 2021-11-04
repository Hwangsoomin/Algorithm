#include<iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> scores;
int n, num;

string answer;
int arr[15][15];
int main(void) {
	scanf("%d", &n);
	scores.assign(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		scores[i].reserve(n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &num);
			scores[i][j] = num;
		}
	}

	for (int i = 0; i < scores.size(); i++) {
		int mine = scores[i][i];
		int Min = 105, cntMin = 0, Max = 0, cntMax = 0;
		double sum = 0;
		int cnt = scores.size();
		for (int j = 0; j < scores[i].size(); j++) {
			sum += scores[j][i];
			if (Min >= scores[j][i]) {
				if (Min == scores[j][i])cntMin += 1;
				else {
					Min = scores[j][i];
					cntMin = 1;
				}
			}
			if (Max <= scores[j][i]) {
				if (Max == scores[j][i])cntMax += 1;
				else {
					Max = scores[j][i];
					cntMax = 1;
				}
			}
		}
		if (Min == mine && cntMin == 1) {
			sum -= mine;
			cnt -= 1;
		}
		if (Max == mine && cntMax == 1) {
			sum -= mine;
			cnt -= 1;
		}

		sum /= (cnt * 1.0);
		if (sum >= 90)answer += 'A';
		else if (sum >= 80)answer += 'B';
		else if (sum >= 70)answer += 'C';
		else if (sum >= 50)answer += 'D';
		else answer += 'F';
	}

	cout << answer << endl;
	return 0;
}