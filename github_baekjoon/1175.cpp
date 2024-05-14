#include<iostream>
#include<string>
#include<queue>
#include<tuple>
using namespace std;
int n, m, map[51][51], x, y, t, d, c, dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} },u=2;
bool visit[51][51][4][4];
string s;
queue<tuple<int, int, int, int, int>>q; // x,y,t,d,c
bool inner(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && map[x][y]!=0)return 1;
	else return 0;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'S') {
				q.push({ i,j,0,-1,0 });
				for(int k=0;k<4;k++)
					visit[i][j][k][0] = 1;
				map[i][j] = 1;
			}
			else if (s[j] == '.') map[i][j] = 1;
			else if (s[j] == 'C') {
				map[i][j] = u; u++;
			}
		}
	}
	int cnt = 2;
	while (!q.empty()) {
		x = get<0>(q.front()), y = get<1>(q.front()), t = get<2>(q.front()), d = get<3>(q.front()), c = get<4>(q.front());
		q.pop();
		for (int dd = 0; dd < 4; dd++) {
			if (dd != d) {
				int dx = x + dir[dd][0], dy = y + dir[dd][1];
				if (inner(dx, dy)) {
					int dc = c;
					if (map[dx][dy] > 1 && dc!=map[dx][dy]) {
						dc += map[dx][dy];
						if (dc>4) {
							cout << t + 1;
							return 0;
						}
					}
					if (!visit[dx][dy][dd][dc]) {
						visit[dx][dy][dd][dc] = 1;
						q.push({ dx,dy,t + 1,dd,dc });
					}
				}
			}
		}
	}
	cout << "-1";
	return 0;
}