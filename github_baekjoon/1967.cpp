#include<iostream>
#include<vector>
using namespace std;
int n,a,b,c, res, resd;
bool visit[10001];
vector<pair<int,int>>v[10001];
void dp(int x, int d) {
	if (resd < d) {
		resd = d;
		res = x;
	}
	for (auto o : v[x]) {
		if (!visit[o.first]) {
			visit[o.first] = 1;
			dp(o.first, d + o.second);
		}
	}
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	visit[1] = 1;
	dp(1, 0);
	fill(visit, visit + 10001, 0);
	visit[res] = 1;
	dp(res, 0);
	cout << resd;
	return 0;
}