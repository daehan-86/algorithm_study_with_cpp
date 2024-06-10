#include<iostream>
#define INF 1000000007
using namespace std;
int n, m, alp[1001][26], res;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	fill(alp[1], alp[2], 1);
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < 26; j++) {
			if (alp[i][j]) {
				for (int d = j + n; d < 26; d++) {
					alp[i + 1][d] = (alp[i + 1][d] + alp[i][j]) % INF;
				}
				for (int d = j - n - (!n); d >= 0; d--) {
					alp[i + 1][d] = (alp[i + 1][d] + alp[i][j]) % INF;
				}
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		res = (res + alp[m][i]) % INF;
	}
	cout << res;
	return 0;
}