#include<iostream>
using namespace std;
int n, m, a, b, map[10001];
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		map[a] = i;
		map[b] = i;
	}
	int k = 0;
	n = (n - 1) % (2 * m) + 1;
	for (int i = 0; i < 10001; i++) {
		if (map[i]) {
			k++;
			if (k == n) {
				cout << map[i];
				return 0;
			}
		}
	}
	return 0;
}