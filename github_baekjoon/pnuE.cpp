#include<iostream>
#include<queue>
#include<string>
#include<tuple>
using namespace std;
typedef tuple<int, int, int>iii;
int n, m, a, b, c, d, dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int visit[2001][2001];
string s[2001];
priority_queue<iii, vector<iii>, greater<iii>>q;
bool inner(int x, int y) {
	if (x > 0 && x <= n && y > 0 && y <= m) return 1;
	else return 0;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	cin >> a >> b >> c >> d;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '.') visit[i+1][j+1] = 1;
			else if (s[i][j] == '#') visit[i+1][j+1] = b;
			else {
				q.push({ 0,i+1,j+1 });
			}
		}
	}
	while (!q.empty()) {
		int time = get<0>(q.top()), x = get<1>(q.top()), y = get<2>(q.top());
		q.pop();
		if (time > a) {
			visit[x][y] = 1;
			continue;
		}
		//cout << time << " " << x << " " << y << "\n";
		for (int d = 0; d < 4; d++) {
			int dx = x + dir[d][0], dy = y + dir[d][1];
			if (inner(dx, dy) && visit[dx][dy]) {
				if (s[dx - 1][dy - 1] == '#') {
					q.push({ time + b + 1,dx,dy });
				}
				else {
					q.push({ time + 1,dx,dy });
				}
				visit[dx][dy] = 0;
			}
		}
	}
	bool state = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visit[i][j]) {
				cout << i << " " << j << "\n";
				state = 0;
			}
		}
	}
	if (state) cout << "-1";
	return 0;
}