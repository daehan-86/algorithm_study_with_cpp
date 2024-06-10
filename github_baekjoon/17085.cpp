#include<iostream>
#include<string>
using namespace std;
int n, m, dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} },res;
string map[16];
void fill_map(int x, int y, int l, char c) {
	for (int i = 0; i <= l; i++) {
		for (int d = 0; d < 4; d++) {
			int dx = x + dir[d][0] * i, dy = y + dir[d][1] * i;
			map[dx][dy] = c;
		}
	}
}
bool inner(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	else return 0;
}
int get_size(int x,int y) {
	for (int l = 0; l < 16; l++) {
		for (int d = 0; d < 4; d++) {
			int dx = x + dir[d][0] * l, dy = y + dir[d][1] * l;
			if (!inner(dx, dy) || map[dx][dy] == '.') {
				return l - 1;
			}
		}
	}
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '#') {
				int M = get_size(i, j);
				for (int k = 0; k <= M; k++) {
					fill_map(i, j, k, '.');
					for (int r = 0; r < n; r++) {
						for (int c = 0; c < m; c++) {
							if (map[r][c] == '#') {
								int MM = get_size(r, c);
								res = max(res, (4 * k + 1) * (4 * MM + 1));
							}
						}
					}
					fill_map(i, j, k, '#');
				}
			}
		}
	}
	cout << res;
	return 0;
}