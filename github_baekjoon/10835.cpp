#include<iostream>
using namespace std;
int cache[2001][2001], n, arr1[2001], arr2[2001];
int dp(int l, int r) {
	//cout << l << " " << r << "\n";
	int& ret = cache[l][r];
	if (l == n || r == n) ret = 0;
	if (ret != -1) return ret;
	ret = 0;
	if (arr1[l] > arr2[r]) {
		ret = max(ret, dp(l, r + 1) + arr2[r]);
	}
	ret = max(ret, max(dp(l + 1, r), dp(l + 1, r + 1)));
	return ret;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	fill(cache[0], cache[2001], -1);
	for (int i = 0; i < n; i++) cin >> arr1[i];
	for (int i = 0; i < n; i++) cin >> arr2[i];
	cout<<dp(0, 0);
	return 0;
}