#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#include<cmath>
#include<map>
#define MOD 1000000003
#define ll long long
using namespace std;
int n, r, m, k, cost, dist[105], ansSum1 = 0, ansSum2 = 0;
vector<int> trip;
map<string, int> city, pt;
string s1, e1, Type;
vector<pair<pair<int, int>, int>> arr[105];
void di1(int num) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, num });
	dist[num] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost)continue;
		for (int i = 0; i < arr[here].size(); i++) {
			int next = arr[here][i].first.first;
			int ncost = arr[here][i].first.second;
			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ dist[next], next });
			}
		}
	}
}
void di2(int num) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, num });
	dist[num] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost)continue;
		for (int i = 0; i < arr[here].size(); i++) {
			int next = arr[here][i].first.first;
			int ncost = arr[here][i].first.second;
			int ntrans = arr[here][i].second;
			if (ntrans <= 3)ncost = 0;
			else if (ntrans <= 5)ncost = ncost / 2;
			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ dist[next], next });
			}
		}
	}
}
int main(void) {
	pt["Mugunghwa"] = 1;
	pt["ITX-Saemaeul"] = 2;
	pt["ITX-Cheongchun"] = 3;
	pt["S-Train"] = 4;
	pt["V-Train"] = 5;
	string str = "";
	scanf("%d%d", &n, &r);
	for (int i = 1; i <= n; i++) {
		cin >> str;
		city[str] = i;
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		cin >> str;
		auto num = city.find(str);
		trip.push_back(num->second);
	}//여행순서
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		cin >> Type >> s1 >> e1;
		scanf("%d", &cost);
		int Tnum = 6;
		auto Snum = city.find(s1);
		auto Enum = city.find(e1);
		if (pt.find(Type) != pt.end()) Tnum = pt.find(Type)->second;
		arr[Snum->second].push_back({ { Enum->second,cost }, Tnum });
		arr[Enum->second].push_back({ {Snum->second,cost},Tnum });
	}
	for (int i = 0; i < trip.size() - 1; i++) {
		for (int j = 1; j <= n; j++)dist[j] = 1e9;
		int num = trip[i];
		di1(num);
		ansSum1 += dist[trip[i + 1]];
	}
	ansSum2 = r;
	for (int i = 0; i < trip.size() - 1; i++) {
		for (int j = 1; j <= n; j++)dist[j] = 1e9;
		int num = trip[i];
		di2(num);
		ansSum2 += dist[trip[i + 1]];
	}
	if (ansSum1 <= ansSum2)printf("No\n");
	else printf("Yes\n");
	return 0;
}