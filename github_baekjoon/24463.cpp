#include<iostream>
#include<string>
using namespace std;
int n, m, s_x, s_y, e_x, e_y, dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
string map[2002],s;
bool inner(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	else return 0;
}
bool dp(int x, int y) {
	map[x][y] = 'k';
	if (x == e_x && y == e_y) {
		return 1;
	}
	bool state = 0;
	for (int d = 0; d < 4; d++) {
		int dx = x + dir[d][0], dy = y + dir[d][1];
		if (inner(dx,dy) && map[dx][dy] == '.') {
			state = 1;
			if (dp(dx, dy)) return 1;
		}
	}
	map[x][y] = '@';
	return 0;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		map[i] = s;
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
				if (s[j] == '.') {
					if (s_x || s_y) {
						e_x = i; e_y = j;
					}
					else {
						s_x = i; s_y = j;
					}
				}
			}
		}
	}
	dp(s_x, s_y);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '.') cout << '@';
			else if (map[i][j] == 'k') cout << '.';
			else cout << map[i][j];
		}
		cout << "\n";
	}
	return 0;
}