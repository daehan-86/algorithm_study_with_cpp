#include<iostream>
using namespace std;
int n, k, s, a, b, stu[100001], t, p, res;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		stu[a] = b;
	}
	t = 0;
	p = -1;
	for (int i = 0; i < s; i++) {
		if (stu[i]) {
			if (p < 0) p = i;
			if (t + stu[i] <= k) {
				t += stu[i];
			}
			else {
				res += (s - p) * 2;
				t = stu[i] - (k - t);
				p = i;
				res += 2 * (s - p) * (t / k);
				t %= k;
				if (!t) p = -1;
			}
		}
	}
	if (t) { res += (s - p) * 2; }
	t = 0;
	p = -1;
	for (int i = 100000; i > s; i--) {
		if (stu[i]) {
			if (p < 0) p = i;
			if (t + stu[i] <= k) {
				t += stu[i];
			}
			else {
				res += (p - s) * 2;
				t = stu[i] - (k - t);
				p = i;
				res += 2 * (p - s) * (t / k);
				t %= k;
				if (!t) p = -1;
			}
		}
	}
	if (t) { res += (p - s) * 2; }
	cout << res;
	return 0;
}