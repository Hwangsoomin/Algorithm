#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<climits>
#include<stack>
#define ll long long
using namespace std;
int n, arr[1005], idx = 1, cnt = 1;
stack<int> st;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
	while (!st.empty() || idx <= n) {
		int n1 = 0;
		if (!st.empty())n1 = st.top();
		if (arr[idx] != cnt) {
			if (n1 == cnt) {
				cnt += 1;
				st.pop();
			}
			else {
				if (n1 != 0) {
					if (n1 < arr[idx])break;
				}
				st.push(arr[idx]);
				idx += 1;
			}
		}
		else {
			idx += 1;
			cnt += 1;
		}
	}
	if (st.empty() && idx == n + 1)printf("Nice\n");
	else printf("Sad\n");
	return 0;
}