#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#include<cmath>
#define MOD 100999
#define ll long long
using namespace std;
int n;
double sum;
pair<double, double> arr[10005], ans[10005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%lf%lf", &arr[i].first, &arr[i].second);
	for (int i = 2; i <= n; i++) {
		double x = arr[i].first - arr[1].first;
		double y = arr[i].second - arr[1].second;
		ans[i - 1] = { x,y };
	}
	for (int i = 1; i < n - 1; i++)
	{
		double num = ans[i].first * ans[i + 1].second - ans[i].second * ans[i + 1].first;
		sum = sum + (num / 2.0);
	}
	printf("%.1lf\n", abs(sum));
	return 0;
}