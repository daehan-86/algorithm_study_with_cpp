#include<iostream>
#include<cmath>
#define INF 1000000007LL
using namespace std;
long long n, x;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		x = abs(x - i);
		if (i % 3 == 0) {
			x *= i;
			if (x >= INF) {
				x %= INF;
			}
		}
		if (i % 15 == 0) {
			x &= i;
		}
		if (i % 63 == 0) {
			x ^= i;
		}
		if (i % 255 == 0) {
			x |= i;
		}
		if (i % 1023 == 0) {
			x <<= i;
			if (x >= INF) {
				x %= INF;
			}
		}
	}
	cout << x;
	return 0;
}