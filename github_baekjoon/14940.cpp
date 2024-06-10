#include<iostream>
#include<queue>
using namespace std;
int n, m, res[1001][1001], x, y, a, dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool map[1001][1001];
queue < pair<int, pair<int, int>>>q;
bool inner(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	else return 0;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	fill(res[0], res[1001], -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			if (a > 1) {
				x = i;
				y = j;
			}
			map[i][j] = a;
			if (!a) {
				res[i][j] = 0;
			}
		}
	}
	map[x][y] = 0;
	q.push({ 0,{x,y} });
	while (!q.empty()) {
		a = q.front().first, x = q.front().second.first, y = q.front().second.second;
		q.pop();
		res[x][y] = a;
		for (int d = 0; d < 4; d++) {
			int dx = x + dir[d][0], dy = y + dir[d][1];
			if (inner(dx, dy) && map[dx][dy]) {
				map[dx][dy] = 0;
				q.push({ a + 1,{dx,dy} });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}