#include<iostream>
using namespace std;
int n, m, s, e, ne[501] = { 0, 1, };
double dp[10001][501];
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	fill(ne + 2, ne + 501, 2);
	cin >> n >> m;
	ne[n] = 1;
	cin >> s >> e;
	dp[0][e] = 1.0;
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i + 1][j] += dp[i][j] * (n - ne[j] - 1) / (n-1);
			if (j == 1) dp[i + 1][j + 1] += dp[i][j]/(n-1);
			else if (j == n) dp[i + 1][j - 1] += dp[i][j]/(n-1);
			else {
				dp[i + 1][j - 1] += dp[i][j] / (n-1);
				dp[i + 1][j + 1] += dp[i][j] / (n-1);
			}
		}
	}
	/*
	for (int j = 0; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			cout << dp[j][i] << " ";
		}
		cout << "\n";
	}
	*/
	cout << dp[m][s];
	return 0;
}