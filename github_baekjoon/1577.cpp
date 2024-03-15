#include<iostream>
using namespace std;
typedef long long ll;
int n, m,k;
ll dp[101][101];
bool r[101][101][2];
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	while (k--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a > c || b > d) {
			swap(a, c);
			swap(b, d);
		}
		r[a][b][a != c] = 1;
	}
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i < n && !r[i][j][1]) dp[i + 1][j] += dp[i][j];
			if (j < m && !r[i][j][0]) dp[i][j + 1] += dp[i][j];
		}
	}
	cout << dp[n][m];
	return 0;
}