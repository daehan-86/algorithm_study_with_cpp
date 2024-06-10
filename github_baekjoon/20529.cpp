#include<iostream>
#include<string>
using namespace std;
int t, n, cnt[16], res;
string s;
int dis(int a, int b) {
	int k = a ^ b, c = 0;
	for (int i = 0; i < 4; i++) {
		if (k & (1 << i)) c++;
	}
	return c;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		res = 10000;
		fill(cnt, cnt + 16, 0);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s;
			int k = 0;
			if (s[0] == 'E') k |= 1 << 0;
			if (s[1] == 'N') k |= 1 << 1;
			if (s[2] == 'F') k |= 1 << 2;
			if (s[3] == 'P') k |= 1 << 3;
			cnt[k]++;
		}
		if (n > 32) {
			cout << "0\n";
			continue;
		}
		for (int i = 0; i < 16; i++) {
			if (!cnt[i]) continue;
			cnt[i]--;
			for (int j = 0; j < 16; j++) {
				if (!cnt[j]) continue;
				cnt[j]--;
				for (int k = 0; k < 16; k++) {
					if (!cnt[k]) continue;
					res = min(res, dis(i, j) + dis(j, k) + dis(i, k));
				}
				cnt[j]++;
			}
			cnt[i]++;
		}
		cout << res << "\n";
	}
	return 0;
}