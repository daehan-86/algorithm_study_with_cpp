#include<iostream>
#include<queue>
#include<string>
using namespace std;
int n, m, dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }, x, y, res;
bool visit[601][601];
string map[601];
queue<pair<int, int>>q;
bool inner(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m)return 1;
	else return 0;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'I') {
				x = i;
				y = j;
				map[i][j] = 'O';
			}
		}
	}
	q.push({ x,y });
	visit[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first, y = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int dx = x + dir[d][0], dy = y + dir[d][1];
			if (inner(dx, dy) && !visit[dx][dy] && map[dx][dy] != 'X') {
				visit[dx][dy] = 1;
				q.push({ dx,dy });
				if (map[dx][dy] == 'P') res++;
			}
		}
	}
	if (res) cout << res;
	else cout << "TT";
	return 0;
}