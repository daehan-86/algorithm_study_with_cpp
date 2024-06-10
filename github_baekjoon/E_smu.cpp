#include<iostream>
#include<vector>
using namespace std;
int n, m, k, sc[100001], a, b, c;
vector<pair<int, int>>v;
int dp(int deep,int win, bool draw) {
	int ret1, ret2, a, b;
	if (deep == v.size()) {
		return !draw && (win == k);
	}
	a = v[deep].first, b = v[deep].second;
	sc[a]++;
	if (sc[a] > sc[win]) {
		ret1 = dp(deep + 1, a, 0);
	}
	else if (sc[a] == sc[win]) {
		if (a == win) {
			ret1 = dp(deep + 1, a, 0);
		}
		else {
			ret1 = dp(deep + 1, a, 1);
		}
	}
	else {
		ret1 = dp(deep + 1, win, draw);
	}
	sc[a]--;
	sc[b]++;
	if (sc[b] > sc[win]) {
		ret2 = dp(deep + 1, b, 0);
	}
	else if (sc[b] == sc[win]) {
		if (b == win) {
			ret2 = dp(deep + 1, b, 0);
		}
		else {
			ret2 = dp(deep + 1, b, 1);
		}
	}
	else {
		ret2 = dp(deep + 1, win, draw);
	}
	sc[b]--;
	return ret1 + ret2;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	int t = 0,w=0;
	bool state = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (c == 1) {
			sc[a]++;
			if (t < sc[a]) {
				t = sc[a];
				w = a;
				state = 0;
			}
			else if (t == sc[a]) state = 1;
		}
		else if (c == 2) {
			sc[b]++;
			if (t < sc[b]) {
				t = sc[b];
				w = b;
				state = 0;
			}
			else if (t == sc[b]) state = 1;
		}
		else {
			v.push_back({ a,b });
		}
	}
	cout<<dp(0, w,state);
	return 0;
}