#include<iostream>
#include<vector>
using namespace std;
int n, t, a, b, res, resd;
bool visit[100001];
vector<pair<int, int>>v[100001];
void dp(int x, int d) {
	if (resd < d) {
		res = x;
		resd = d;
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
	for (int i = 0; i < n; i++) {
		cin >> t;
		while (1) {
			cin >> a;
			if (a == -1) break;
			cin >> b;
			v[t].push_back({ a,b });
		}
	}
	visit[1] = 1;
	dp(1, 0);
	fill(visit, visit + 100001, 0);
	resd = 0;
	visit[res] = 1;
	dp(res, 0);
	cout << resd;
	return 0;
}