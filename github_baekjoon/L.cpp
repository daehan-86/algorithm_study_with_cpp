#include<iostream>
#include<queue>
using namespace std;
int n, m, map[101][101],target,x,y,z;
bool visit[101][101];
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
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cin >> z;
	if (map[0][0] != map[n - 1][m - 1]) {
		cout << "DEAD";
		return 0;
	}
	target = map[0][0];
	q.push({ 0,0 });
	visit[0][0] = 1;
	while (!q.empty()) {
		x = q.front().first, y = q.front().second;
		//cout << x << " " << y <<"    "<<q.size() << "\n";
		q.pop();
		if (x == n - 1 && y == m - 1) {
			cout << "ALIVE";
			return 0;
		}
		for (int dx = x - z; dx <= x + z; dx++) {
			for (int dy = y - z; dy <= y + z; dy++) {
				if (abs(dx-x)+abs(dy - y) <= z) {
					if (inner(dx, dy) && map[dx][dy] == target && !visit[dx][dy]) {
						visit[dx][dy] = 1;
						q.push({ dx,dy });
					}
				}
			}
		}
	}
	cout << "DEAD";
	return 0;
}