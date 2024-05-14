#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v1, v2;
int n, a, m, b[51],res;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v1.push_back(a);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		v2.push_back(a);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(),greater<>());
	for (auto t : v2) {
		bool state = 0;
		for (int i = 0; i < n; i++) {
			if (state) {
				if (i<n - 1 && b[i] + 1>b[i + 1]) {
					continue;
				}
				else {
					b[i]++;
					res = max(res, b[i]);
					break;
				}
			}
			else {
				if (v1[i] < t) {
					continue;
				}
				else {
					state = 1;
					i--;
				}
			}
		}
		if (!state) {
			cout << "-1";
			return 0;
		}
	}
	cout << res;
	return 0;
}