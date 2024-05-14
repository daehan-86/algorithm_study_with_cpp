#include<iostream>
#include<string>
#define INF 2147483647
using namespace std;
int n, m, map[51][51], cache[51][51], dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool visit[51][51];
string s;
bool inner(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && map[x][y]>0)return 1;
	else return 0;
}
int dp(int x, int y) {
	if (visit[x][y]) return -1;
	int& ret = cache[x][y];
	if (ret) return ret + 1;
	visit[x][y] = 1;
	for (int d = 0; d < 4; d++) {
		int dx = x + map[x][y] * dir[d][0], dy = y + map[x][y] * dir[d][1];
		if (inner(dx, dy)) {
			int k = dp(dx, dy);
			if (k < 0) return -1;
			ret = max(ret, k);
		}
	}
	visit[x][y] = 0;
	return ret + 1;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
			if (s[j] == 'H') map[i][j] = -1;
		}
	}
	cout<<dp(0, 0);
	return 0;
}