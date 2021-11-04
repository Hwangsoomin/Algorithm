#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue> 
#include<cmath>
#include<map>
#include<climits>
#include<bitset>
#define ll long long
using namespace std;
ll n, nq, pre = 1, nn;
string q;
vector<ll> arr;
void go(ll here) {
	string str = "";
	while (here > 1) {
		str += ((here % 2) + '0');
		here /= 2;
	}
	if (here == 1)str += '1';
	reverse(str.begin(), str.end());
	for (int i = str.length(); i < n; i++)cout << '0';
	cout << str << "\n";
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i = q.length() - 1; i >= 0; i--) {
		if (q[i] == '1')nq += pow(2, (q.length() - 1) - i);
	}
	nn = pow(2, n);
	for (int i = 0; i < nn / 2; i++) {
		ll hnum = i ^ (i >> 1);
		arr.push_back(hnum);
		arr.push_back((nn - 1) - hnum);
	}
	for (int i = 0; i < arr.size(); i++) {
		go(arr[i] ^ nq);
	}
	return 0;
}