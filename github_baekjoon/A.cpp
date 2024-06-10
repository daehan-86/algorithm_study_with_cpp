#include<iostream>
using namespace std;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int s[8][3] = {{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
	int t,v[4];
	cin >> t;
	while (t--) {
		bool state = 1;
		for (int i = 0; i < 4; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < 3; i++) {
			state = 1;
			for (int j = 1; j < 4; j++) {
				if (s[v[j]][i] != s[v[0]][i]) {
					state = 0;
					break;
				}
			}
			if (state) break;
		}
		if (state) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}