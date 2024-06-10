#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n, a, c, s;
vector<int>v;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	if (!n) {
		cout << "0";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	c = (int)round((double)n * 0.15);
	sort(v.begin(), v.end());
	for (int i = c; i < n - c; i++) {
		s += v[i];
	}
	cout << (int)round((double)s / (n - 2 * c));
	return 0;
}