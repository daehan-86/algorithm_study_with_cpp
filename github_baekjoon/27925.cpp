#include<iostream>
#define INF 2147483647
using namespace std;
int n, cache[5001][10][10][10],v[5001];
int dp(int d, int a, int b, int c) {
	int& ret = cache[d][a][b][c];
	if (d == n)ret = 0;
	if (ret != -1)return ret;
	ret = INF;
	ret = min(ret, dp(d + 1, v[d], b, c) + (abs(a - v[d]) > 5 ? 10 - abs(a - v[d]) : abs(a - v[d])));
	ret = min(ret, dp(d + 1, a, v[d], c) + (abs(b - v[d]) > 5 ? 10 - abs(b - v[d]) : abs(b - v[d])));
	ret = min(ret, dp(d + 1, a, b, v[d]) + (abs(c - v[d]) > 5 ? 10 - abs(c - v[d]) : abs(c - v[d])));
	return ret;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	fill(cache[0][0][0], cache[5001][0][0], -1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << dp(0, 0, 0, 0);
	return 0;
}