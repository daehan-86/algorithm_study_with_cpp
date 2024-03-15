#include<iostream>
#define INF 1000000000
using namespace std;

int map[201][201],first[201][201];
int first_road(int s,int e,int x) {
	if (first[s][x] == x) return x;
	else return first_road(s, x, first[s][x]);
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m, a, b, c;
	cin >> n >> m;
	fill(map[0], map[201], INF);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		map[a][b] = c;
		map[b][a] = c;
		first[a][b] = b;
		first[b][a] = a;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i][k] + map[k][j]) {
					first[i][j] = first_road(i,j,k);
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)cout << "- ";
			else cout << first[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}