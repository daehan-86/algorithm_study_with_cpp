#include<iostream>
#include<string>
#include<queue>
#include<tuple>
using namespace std;
int n, m, map[1001][1001], res, dir[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} },x,y,t;
bool visit[1001][1001];
string s;
queue<tuple<int, int, int>>q;
bool inner(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	else return 0;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '.') {
				map[i][j] = 0;
				q.push({ 0,i,j });
				visit[i][j] = 1;
			}
			else map[i][j] = s[j] - '0';
		}
	}

	while (!q.empty()) {
		t = get<0>(q.front()), x = get<1>(q.front()), y = get<2>(q.front());
		q.pop();
		res = t;
		for (int d = 0; d < 8; d++) {
			int dx = x + dir[d][0], dy = y + dir[d][1];
			if (inner(dx, dy)&&map[dx][dy]) {
				map[dx][dy]--;
				if (!map[dx][dy]) q.push({ t + 1,dx,dy });
			}
		}
	}
	cout << res;
	return 0;
}