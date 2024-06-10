#include<iostream>
using namespace std;
int n,dp[27][5];
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		fill(dp[0], dp[27], 0);
		dp[0][0] = 1;
		for (int i = 0; i < n; i++) {
			//가로채우기
			if (dp[i][0]) {
				dp[i + 1][0] += dp[i][0];
				dp[i + 1][1] += dp[i][0];
				dp[i + 1][2] += dp[i][0];
				dp[i + 1][4] += dp[i][0];
				dp[i + 2][0] += dp[i][0];
			}
			if (dp[i][1]) {
				dp[i + 1][2] += dp[i][1];
				dp[i + 1][0] += dp[i][1];
			}
			if(dp[i][2]){
				dp[i + 1][1] += dp[i][2];
				dp[i + 1][0] += dp[i][2];
			}
			if(dp[i][3]){
				dp[i + 1][4] += dp[i][3];
			}
			if(dp[i][4]){
				dp[i + 1][3] += dp[i][4];
				dp[i + 1][0] += dp[i][4];
			}
		}
		cout << dp[n][0] << "\n";
		
	}
	return 0;
}