//보이저 1호
#include<iostream>
#include<string>
#define INF 2147483647
using namespace std;
int n, m, x, y, resd, res, dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
char map[501][501], name[4] = { 'U','R','D','L' };
bool visit[501][501][4];
bool inner(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	else return 0;
}
int turn(char c, int d) {
	if (c == '/') {
		if (d == 0) return 1;
		if (d == 1) return 0;
		if (d == 2) return 3;
		if (d == 3) return 2;
	}
	else {
		if (d == 0) return 3;
		if (d == 1) return 2;
		if (d == 2) return 1;
		if (d == 3) return 0;
	}
}
int sim(int x, int y, int d) {
	if (!inner(x, y) || map[x][y] == 'C') return 0;
	if (visit[x][y][d]) return INF;
	visit[x][y][d] = 1;
	if (map[x][y] != '.') {
		d = turn(map[x][y], d);
	}
	int dx = x + dir[d][0], dy = y + dir[d][1];
	int ret = sim(dx, dy, d);
	if (ret == INF) return ret;
	else return ret + 1;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cin >> x >> y;
	for (int i = 0; i < 4; i++) {
		fill(visit[0][0], visit[501][0], 0);
		int t = sim(x-1, y-1, i);
		if (res < t) {
			res = t;
			resd = i;
		}
	}
	cout << name[resd] << "\n";
	if (res == INF) cout << "Voyager";
	else cout << res;
	return 0;
}