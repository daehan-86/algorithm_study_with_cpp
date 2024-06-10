/*
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, k,a,b,c;
bool vi[1001],visit[1001];
queue<pair<int, int>>q;
vector<pair<int, int>>v[1001];
vector<int>start;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> a;
		start.push_back(a);
		vi[a] = 1;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[b].push_back({ c,a });
	}
	for (auto o : start) {
		q = queue<pair<int, int>>();
		fill(visit, visit + 1001, 0);
		q.push({ o,0 });
		visit[o] = 1;
		bool state = 0;
		while (!q.empty()) {
			a = q.front().first, b = q.front().second;
			q.pop();
			for (auto t : v[a]) {
				if (t.second > b) {
					if (!vi[t.first]) {
						state = 1;
						break;
					}
					else if (!visit[t.first]) {
						visit[t.first] = 1;
						q.push(t);
					}
				}
			}
			if (state)break;
		}
		for (int i = 0; i < 1001; i++) {
			if (visit[i] != vi[i]) {
				state = 1;
				break;
			}
		}
		if (!state) {
			cout << o;
			return 0;
		}
	}
	return 0;
}
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, k,a,b,c;
bool vi[1001], res[1001];
vector<pair<int, pair<int, int>>>v;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> a;
		vi[a] = 1;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v.push_back({ a,{b,c} });
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		if (vi[i]) {
			fill(res, res + 1001, 0);
			res[i] = 1;
			for (auto o : v) {
				a = o.first, b = o.second.first, c = o.second.second;
				if (!res[c]) {
					if (res[b]) {
						res[c] = 1;
					}
				}
			}
			bool state = 1;
			for (int j = 1; j <= n; j++) {
				if (vi[j] != res[j]) state = 0;
			}
			if (state) {
				cout << i;
				return 0;
			}
		}
	}
	return 0;
}