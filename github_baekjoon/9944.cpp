#include<iostream>
#include<string>
#define INF 2147483647
using namespace std;
int n, m, dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} },res=INF;
bool visit[31][31];
string map[31];
void fill_visit(int x, int y, int d, int dis, int k) {
	for (int i = 1; i <= dis; i++) {
		visit[x + dir[d][0] * i][y + dir[d][1] * i] = k;
	}
}
bool inner(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	else return 0;
}
int dp(int x, int y, int deep) {
	int dx, dy, ret = INF;
	bool state = 1;
	for (int d = 0; d < 4; d++) {
		int dis;
		for (dis = 1; dis < 31; dis++) {
			dx = x + dir[d][0] * dis, dy = y + dir[d][1] * dis;
			if (!inner(dx, dy) || visit[dx][dy] || map[dx][dy] == '*') break;
		}
		dis--;
		if (dis) {
			state = 0;
			fill_visit(x, y, d, dis, 1);
			ret = min(ret,dp(x + dir[d][0] * dis, y + dir[d][1] * dis, deep + 1));
			fill_visit(x, y, d, dis, 0);
		}
	}
	if (state) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == '.' && !visit[i][j]) {
					return INF;
				}
			}
		}
		return deep;
	}
	else return ret;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t = 1;
	while (1) {
		res = INF;
		cin >> n >> m;
		if (cin.eof()) break;
		for (int i = 0; i < n; i++) {
			cin >> map[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == '.') {
					fill(visit[0], visit[31], 0);
					visit[i][j] = 1;
					res = min(res, dp(i, j, 0));
				}
			}
		}
		cout << "Case " << t << ": ";
		if (res == INF) cout << "-1\n";
		else cout << res << "\n";
		t++;
	}
	return 0;
}