#include<iostream>
#include<cmath>
using namespace std;
int n;
char alpha(int r, int c) {
	r %= 2 * n - 1;
	c %= 2 * n - 1;
	r -= n - 1;
	c -= n - 1;
	int t = abs(r) + abs(c);
	if (t >= n) return '.';
	else {
		if (t >= 26) t %= 26;
		return 'a' + t;
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int r1, c1, r2, c2;
	cin >> n >> r1 >> c1 >> r2 >> c2;

	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			cout << alpha(i, j);
		}
		cout << "\n";
	}

	return 0;
}