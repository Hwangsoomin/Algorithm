#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n;
vector<pair<char, char>> tree[200];
void pre(char c) {
	if (c == '.')return;
	char le = tree[c].front().first;
	char ri = tree[c].front().second;
	printf("%c", c);
	pre(le);
	pre(ri);
}
void in(char c) {
	if (c == '.')return;
	char le = tree[c].front().first;
	char ri = tree[c].front().second;
	in(le);
	printf("%c", c);
	in(ri);
}
void po(char c) {
	if (c == '.')return;
	char le = tree[c].front().first;
	char ri = tree[c].front().second;
	po(le);
	po(ri);
	printf("%c", c);
}
int main(void) {
	char c1, c2, c3;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %c %c %c", &c1, &c2, &c3);
		tree[c1].push_back({ c2,c3 });
	}
	pre('A');
	printf("\n");
	in('A');
	printf("\n");
	po('A');
	printf("\n");
	return 0;
}