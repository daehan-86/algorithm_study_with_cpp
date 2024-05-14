#include<iostream>
#include<queue>
using namespace std;

int n, m, a[301][301], year, dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool visit[301][301],v[301][301];
queue<pair<int, int>>q;
bool inner(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	else return 0;
}
bool check() {
	fill(v[0], v[301], 0);
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] && !v[i][j]) {
				v[i][j] = 1;
				q.push({ i,j });
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int d = 0; d < 4; d++) {
						int dx = x + dir[d][0], dy = y + dir[d][1];
						if (inner(dx, dy) && !v[dx][dy] && a[dx][dy]) {
							q.push({ dx,dy });
							v[dx][dy] = 1;
						}
					}
				}
				k++;
			}
		}
	}
	return k > 1;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	while (1) {
		int cnt=n*m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!a[i][j]) {
					visit[i][j] = 1;
					cnt--;
				}
			}
		}
		if (!cnt) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visit[i][j]) {
					for (int d = 0; d < 4; d++) {
						int dx = i + dir[d][0], dy = j + dir[d][1];
						if (inner(dx, dy)) {
							a[i][j] = max(0, a[i][j] - visit[dx][dy]);
						}
					}
				}
			}
		}
		year++;
		if (check()) {
			cout << year;
			return 0;
		}
	}
	cout << "0";
	return 0;
}