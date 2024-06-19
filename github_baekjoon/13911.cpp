#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#define INF 2147483647
using namespace std;
int n, k, a, b, c, n_m, x, n_s, y;
unordered_map<int,int>v[10001];
bool visit[10001];
priority_queue<pair<int, int>>pq;
void dijkstra(vector<int>& res, int m) {
	while (!pq.empty()) {
		int p = pq.top().second, dis = -pq.top().first;
		pq.pop();
		if (res[p] < dis || m<dis) continue;
		for (auto o : v[p]) {
			int dd = dis + o.second;
			if (dd < res[o.first] && dd<=m) {
				res[o.first] = dd;
				pq.push({ -dd, o.first });
			}
		}
	}
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c;
		if (v[a].find(b) != v[a].end()) v[a][b] = min(c, v[a][b]);
		else v[a][b] = c;
		if (v[b].find(a) != v[b].end()) v[b][a] = min(c, v[b][a]);
		else v[b][a] = c;
	}
	cin >> n_m >> x;
	vector<int>min_mac(n + 1, INF);
	for (int i = 0; i < n_m; i++) {
		cin >> a;
		visit[a] = 1;
		pq.push({ 0,a });
		min_mac[a] = 0;
	}
	dijkstra(min_mac,x);
	cin >> n_s >> y;
	vector<int>min_sta(n + 1, INF);
	for (int i = 0; i < n_s; i++) {
		cin >> a;
		visit[a] = 1;
		pq.push({ 0,a });
		min_mac[a] = 0;
	}
	dijkstra(min_sta,y);
	int res = INF;
	for (int i = 1; i <= n; i++) {
		//cout << min_mac[i] << " " << min_sta[i] << "\n";
		if (!visit[i]&&min_mac[i] <= x && min_sta[i] <= y) {
			res = min(res, min_mac[i] + min_sta[i]);
		}
	}
	if (res == INF) cout << "-1";
	else cout << res;
	return 0;
}