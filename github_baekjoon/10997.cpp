#include<iostream>
using namespace std;
bool map[500][500],state;
int n, m, x, y, d, dir[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };
bool inner(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	else return 0;
}
int main(void) {
	cin >> n;
	if (n == 1) {
		cout << "*";
		return 0;
	}
	m = 4 * n - 3;
	n = 4 * n - 1;
	y = m - 1;
	while (1) {
		int dx = x + dir[d][0], dy = y + dir[d][1];
		if (inner(dx, dy)&&!map[dx][dy]) {
			map[x][y] = 1;
			state = 0;
			x = dx, y = dy;
		}
		else {
			if (map[dx][dy]) {
				if (state) break;
				map[x][y] = 0;
				x -= dir[d][0];
				y -= dir[d][1];
			}
			d = (d + 1) % 4;
			state = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i == 1) {
			cout << "*\n";
			continue;
		}
		for (int j = 0; j < m; j++) {
			cout << (map[i][j]?'*':' ');
		}
		cout << "\n";
	}
	return 0;
}