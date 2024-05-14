#include<iostream>

using namespace std;
int a[2001],dp[2001][2001],res; // s,e
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i + j == n) {
				res = max(res, dp[i][j]);
				break;
			}
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + a[n - j - 1] * (i + j + 1));
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i] * (i + j + 1));
		}
	}
	cout << res;
	return 0;
}