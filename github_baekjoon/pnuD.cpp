#include<iostream>
using namespace std;
int n, p, cnt[500001], t, max_a, bag = 0, max_b = 0, pre=0;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> p;
	max_a = n / p;
	if (n % p) max_a++;
	bool state = 1;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t > max_a || t<pre || t>pre+1) {
			state = 0;
			break;
		}
		max_b = min(t * p, n);
		bag++;
		if (max_b < bag) {
			state = 0;
			break;
		}
		pre = t;
	}
	if (state) cout << "YES";
	else cout << "NO";
	return 0;
}