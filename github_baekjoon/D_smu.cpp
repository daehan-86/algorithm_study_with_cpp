#include<iostream>
#include<queue>
#include<string>
using namespace std;
int n, m, dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }, x, y, dx, dy, c, cnt;
string map[1001];
queue<pair<int, int>>q;
bool inner(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	else return 0;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '@') {
				x = i;
				y = j;
				map[i][j] = '.';
			}
			if (map[i][j] == '*' || map[i][j] == '#') cnt++;
		}
	}
	for (int d = 0; d < 4; d++) {
		for (int i = 1; i < 3; i++) {
			dx = x + dir[d][0] * i, dy = y + dir[d][1] * i;
			if (inner(dx, dy)) {
				if (map[dx][dy] == '|') break;
				if (map[dx][dy] == '*') {
					map[dx][dy] = '.';
					q.push({ dx,dy });
					c++;
				}
				if (map[dx][dy] == '#') {
					map[dx][dy] = '*';
				}
			}
		}
	}
	while (!q.empty()) {
		x = q.front().first, y = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			dx = x + dir[d][0], dy = y + dir[d][1];
			if (inner(dx, dy)) {
				if (map[dx][dy] == '*') {
					map[dx][dy] = '.';
					q.push({ dx,dy });
					c++;
				}
				if (map[dx][dy] == '#') {
					map[dx][dy] = '*';
				}
			}
		}
	}
	cout << c << " " << cnt - c;
	return 0;
}