#include<iostream>
#include<queue>
#include<string>
using namespace std;
int n, m, k, h, dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool visit[101][101];
string map[101];
queue<pair<int, int>>q;
bool inner(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	else return 0;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	cin >> k;
	for (int t = 0; t < k; t++) {
		cin >> h;
		h = n - h;
		int i;
		bool state = 1;
		if (t % 2) {
			for (i = m - 1; i >= 0; i--) {
				if (map[h][i] == 'x') {
					map[h][i] = '.';
					state = 0;
					break;
				}
			}
		}
		else {
			for (i = 0; i < m; i++) {
				if (map[h][i] == 'x') {
					map[h][i] = '.';
					state = 0;
					break;
				}
			}
		}
		if (state) continue;
		fill(visit[0], visit[101], 0);
		for (int d = 0; d < 4; d++) {
			state = 0;
			int sx = dir[d][0] + h, sy = dir[d][1] + i;
			if (inner(sx, sy) && map[sx][sy] == 'x' && !visit[sx][sy]) {
				fill(visit[0], visit[101], 0);
				q.push({ sx,sy });
				visit[sx][sy] = 1;
				state = 1;
				while (!q.empty()) {
					sx = q.front().first, sy = q.front().second;
					q.pop();
					if (sx == n - 1) state = 0;
					for (int i = 0; i < 4; i++) {
						int dx = sx + dir[i][0], dy = sy + dir[i][1];
						if (inner(dx, dy) && map[dx][dy] == 'x' && !visit[dx][dy]) {
							q.push({ dx,dy });
							visit[dx][dy] = 1;
						}
					}
				}
				if (state)break;
			}
		}
		if (state) {
			int move = 10000;
			for (int i = 0; i < n-1; i++) {
				for (int j = 0; j < m; j++) {
					if (visit[i][j] && map[i + 1][j] == '.') {
						int dd;
						for (dd = 2; dd + i < n; dd++) {
							if (map[dd + i][j] == 'x' && !visit[dd + i][j]) {
								break;
							}
						}
						move = min(move, dd - 1);
					}
				}
			}
			for (int i = n-1; i >= 0; i--) {
				for (int j = 0; j < m; j++) {
					if (visit[i][j]) {
						map[i][j] = '.';
						map[i + move][j] = 'x';
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << map[i] << "\n";
	}
	return 0;
}