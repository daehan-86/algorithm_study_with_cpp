#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n, m, d, t, map[501][501], dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int visit[501][501];
queue<pair<int,int>>q;
priority_queue<tuple<int, int, int>>pq;
bool inner(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	else return 0;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		int res = 0;
		cin >> n >> m >> d;
		fill(visit[0], visit[501], 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				pq.push({ map[i][j],i,j });
			}
		}
		while (!pq.empty()) {
			int px = get<1>(pq.top()), py = get<2>(pq.top()), pm = get<0>(pq.top());
			pq.pop();
			if (visit[px][py]) continue;
			/*
			cout << "-----------------------\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << visit[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "¹æ¹® : " << px << " " << py << "\n";
			*/
			q.push({ px,py });
			visit[px][py] = pm+1;
			int cnt = 1;
			bool state = 0;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int dd = 0; dd < 4; dd++) {
					int dx = x + dir[dd][0], dy = y + dir[dd][1];
					if (inner(dx, dy)) {
						if (visit[dx][dy]) {
							if (pm + 1 < visit[dx][dy]) {
								state = 1;
							}
						}
						else {
							if (pm - map[dx][dy] < d) {
								if (pm == map[dx][dy]) cnt++;
								visit[dx][dy] = pm + 1;
								q.push({ dx,dy });
							}
						}
					}
				}
			}
			if (!state) res += cnt;
			/*
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << visit[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "result : " << res<<"\n";
			*/
		}
		cout << res << "\n";
	}
	return 0;
}