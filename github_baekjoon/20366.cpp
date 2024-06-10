#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define INF 2147483647
using namespace std;
int n, a, map[601][601], res = INF, l, r;
vector<int>v;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n-3; ++i) {
		for (int j = i + 3; j < n; ++j) {
			l = i + 1;
			r = j - 1;
			while (l < r) {
				a = (v[i] + v[j]) - (v[l] + v[r]);
				res = min(res, abs(a));
				if (a < 0) {
					r--;
				}
				else {
					l++;
				}
			}
		}
	}
	cout << res;
	return 0;
}