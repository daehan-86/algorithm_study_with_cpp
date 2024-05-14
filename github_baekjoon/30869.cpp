#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#define INF 2147483647
using namespace std;
typedef tuple<int, int, int> t;
int n, m, k, a, b, c, d, res[501][501], result = INF;
vector<t>v[501];
priority_queue<t,vector<t>,greater<t>>q;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	fill(res[0], res[501], INF);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c >> d;
		v[a].push_back({b,c,d});
	}
	q.push({ 0,1,0 });
	res[1][k] = 0;
	while (!q.empty()) {
		a = get<0>(q.top()), b = get<1>(q.top()), c = get<2>(q.top());
		//cout << a << " " << b << " " << c << "\n";
		q.pop();
		if (b == n) {
			cout << a;
			return 0;
		}
		for (auto o : v[b]) {
			int next = get<0>(o), cost = get<1>(o), dcost = get<2>(o);
			if (res[next][c] > a + cost + (dcost - a % dcost) % dcost) {
				res[next][c] = a + cost + (dcost - a % dcost) % dcost;
				q.push({ res[next][c],next,c });
			}
			if (c!=k && res[next][c + 1] > a + cost) {
				res[next][c + 1] = a + cost;
				q.push({ res[next][c + 1],next,c + 1 });
			}
		}
		v[b].clear();
	}
	for (int i = 0; i <= k; i++) {
		result = min(result, res[n][i]);
	}
	if (result == INF) cout << "-1";
	else cout << result;
	return 0;
}