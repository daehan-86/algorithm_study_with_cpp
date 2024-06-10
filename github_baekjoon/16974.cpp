#include<iostream>
using namespace std;
typedef long long ll;
ll n, x, pati[51], bur[51];
ll dp(ll level, ll x) {
	if (!level) return 1LL;
	if (x == 1) return 0LL;
	x--;
	if (bur[level - 1] >= x) {
		return dp(level - 1, x);
	}
	x -= bur[level - 1];
	if (x == 1) return pati[level - 1] + 1LL;
	x--;
	if (bur[level - 1] >= x) {
		return dp(level - 1, x) + pati[level - 1] + 1LL;
	}
	return pati[level];
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	bur[0] = 1;
	pati[0] = 1;
	for (int i = 0; i < 50; i++) {
		bur[i + 1] = bur[i] * 2 + 3;
		pati[i + 1] = pati[i] * 2 + 1;
	}
	cin >> n >> x;
	cout<<dp(n, x);
	return 0;
}